#include "adj_matrix.h"

#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "timer.h"

/* Tipo de dados das celulas da matriz de adjacencia */
#define AMT char

// clang-format off
#define swap(x, y) __extension__({ IDT tmp = x; x = y; y = tmp; })
#define conv(s, i, j) ( (i * s + j) - (((i + 1) * (i + 2)) / 2) )
// clang-format on

struct adj_matrix_st
{
    IDT dim;
    AMT *vet;
};

Adj_matrix *adj_mat_init(IDT dim)
{
    Adj_matrix *m = (Adj_matrix *)malloc(sizeof(struct adj_matrix_st));
    m->vet = (AMT *)calloc((dim * (dim - 1) / 2), sizeof(AMT));
    m->dim = dim;
    return m;
}

void adj_mat_free(Adj_matrix *m)
{
    free(m->vet);
    free(m);
}

int adj_mat_get(Adj_matrix *m, IDT i, IDT j)
{
    if (i == j) return 0.0f;
    if (i > j) swap(i, j);
    return (int)(m->vet[conv(m->dim, i, j)]);
}

void adj_mat_set(Adj_matrix *m, IDT i, IDT j, int w)
{
    if (i == j) return;
    if (i > j) swap(i, j);
    m->vet[conv(m->dim, i, j)] = (AMT)w;
}

void adj_mat_fprint(Adj_matrix *m, FILE *f)
{
    IDT i, j;
    double start = timer_clock();
    for (i = 0; i < m->dim; i++)
        for (j = i + 1; j < m->dim; j++)
            if (adj_mat_get(m, i, j)) fprintf(f, IDF " " IDF "\n", i + 1, j + 1);
    // +1 ao valor final pois os indices da matriz comecam em zero

    double end = timer_clock();
    timer_print(start, end, "Escrita mst");
    
}