#include "bytes.h"

#include <stdlib.h>

#include "assertr.h"

struct bytes_st
{
    long len;
    unsigned char *vet;
};

Bytes *bytes_init(long size)
{
    Bytes *by = (Bytes *)malloc(sizeof(struct bytes_st));
    by->vet = (unsigned char *)calloc(size, sizeof(unsigned char));
    by->len = size;
    return by;
}

void bytes_free(Bytes *by)
{
    assertx(by != NULL, "Tentando liberar Bytes não alocados");
    free(by->vet);
    free(by);
}

unsigned char bytes_get(Bytes *by, long idx)
{
    return by->vet[idx];
}

void bytes_set(Bytes *by, long idx, unsigned char v)
{
    by->vet[idx] = v;
}

unsigned char *bytes_contents(Bytes *by)
{
    return by->vet;
}

long bytes_len(Bytes *by)
{
    return by->len;
}
