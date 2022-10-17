#include "bytes.h"

#include <stdlib.h>

#include "assertr.h"

struct bytes_st
{
    long len;
    double *vet;
};

Bytes *bytes_init(long size)
{
    Bytes *by = (Bytes *)malloc(sizeof(struct bytes_st));
    by->vet = (double *)calloc(size, sizeof(double));
    by->len = size;
    return by;
}

void bytes_free(Bytes *by)
{
    assertx(by != NULL, "Tentando liberar Bytes não alocados");
    free(by->vet);
    free(by);
}

double bytes_get(Bytes *by, long idx)
{
    return by->vet[idx];
}

void bytes_set(Bytes *by, long idx, double v)
{
    by->vet[idx] = v;
}

double *bytes_contents(Bytes *by)
{
    return by->vet;
}

long bytes_len(Bytes *by)
{
    return by->len;
}
