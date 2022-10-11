#include "UF.h"

#include <stdlib.h>
#include <stdio.h> // So para print

#define CEL unsigned long int

struct uf_st
{
    CEL *id;
    CEL *w;
    CEL len;
};

UF *UF_init(unsigned long int len)
{
    UF *uf = (UF *)malloc(sizeof(struct uf_st));
    uf->id = (CEL *)malloc(len * sizeof(CEL));
    uf->w = (CEL *)calloc(len, sizeof(CEL));
    uf->len = len;

    CEL i;
    for (i = 0; i < len; i++)
        uf->id[i] = i;

    return uf;
}

void UF_free(UF *uf)
{
    free(uf->id);
    free(uf->w);
    free(uf);
}

void UF_union(UF *uf, unsigned long int a, unsigned long int b)
{
    a = UF_find(uf, a);
    b = UF_find(uf, b);

    if (a == b)
        return;

    if (uf->w[a] > uf->w[b])
    {
        uf->id[b] = a;
        uf->w[a] += uf->w[b];
    }
    else
    {
        uf->id[a] = b;
        uf->w[b] += uf->w[a];
    }
}

int UF_connected(UF *uf, unsigned long int a, unsigned long int b)
{
    return (UF_find(uf, a) == UF_find(uf, b));
}

unsigned long int UF_find(UF *uf, unsigned long int f)
{
    while (f != uf->id[f])
    {
        uf->id[f] = uf->id[uf->id[f]]; // Path halving
        f = uf->id[f];
    }
        
    return f;
}

void UF_print(UF* uf)
{
    CEL i;
    for (i = 0; i < uf->len; i++)
        printf("id[%li] = %li\n", i, uf->id[i]);
}