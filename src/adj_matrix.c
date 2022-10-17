#include "adj_matrix.h"

#include <stdio.h>
#include <stdlib.h>

// clang-format off
/* Economizando linhas rs / TODO: tem como fazer isso sem extensao do gcc? */
#define swap(x, y) __extension__({ long tmp = x; x = y; y = tmp; })
#define conv(s, i, j) ( (s -1) * (i) + j - i - 1)
// clang-format on

static long convertion(long s, long lin, long col){
    long k = 0, soma=0;

    k = lin * s + col;

    soma = (lin+1)*(1+lin+1)/2;

    k-= soma;

    return k;
}

struct adj_matrix_st
{
    unsigned int dim;
    double *vet;
};

static unsigned char adj_mat_get(Adj_matrix *m, long i, long j)
{
    return m->vet[convertion(m->dim, i, j)];
}

static void adj_mat_set(Adj_matrix *m, long i, long j, double w)
{
    m->vet[convertion(m->dim, i, j)] = w;
}

Adj_matrix *adj_mat_init(long dim)
{
    Adj_matrix *m = (Adj_matrix *)malloc(sizeof(struct adj_matrix_st));
    m->vet = (double *)calloc((dim * (dim - 1) / 2), sizeof(double));
    m->dim = dim;
    return m;
}

void adj_mat_free(Adj_matrix *m)
{
    free(m->vet);
    free(m);
}

void adj_mat_connect(Adj_matrix *m, long i, long j, double w)
{
    if (i == j) return;
    if (i > j) swap(i, j);
    if (!adj_mat_get(m, i, j)) adj_mat_set(m, i, j, w);
}

void adj_mat_fprint(Adj_matrix *m, FILE *f)
{
    long i, j;
    for (i = 0; i < m->dim; i++)
        for (j = i + 1; j < m->dim; j++)
            if (adj_mat_get(m, i, j)) fprintf(f, "%li %li\n", i+1, j+1);

    // i e j + 1 por conta do index começar em 0
}