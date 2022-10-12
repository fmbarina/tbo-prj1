#include "assertr.h"
#include "bytes.h"
#include <stdlib.h>

struct bytes_st
{
    unsigned long int len;
    unsigned char *vet;
};

Bytes *bytes_init(unsigned long int size)
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

unsigned char bytes_get(Bytes *by, unsigned long int idx)
{
    return by->vet[idx];
}

void bytes_set(Bytes *by, unsigned long int idx, unsigned char v)
{
    by->vet[idx] = v;
}

unsigned char *bytes_contents(Bytes *by)
{
    return by->vet;
}

unsigned long int bytes_len(Bytes *by)
{
    return by->len;
}
