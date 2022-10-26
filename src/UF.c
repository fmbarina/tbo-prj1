#include "UF.h"
#include "assertx.h"
#include <stdlib.h>

/* Baseado no QWUF disponibilizado pelo professor */

struct uf_st
{
    UF_CEL *id;
    UF_CEL *w;
    UF_CEL len;
};

UF *UF_init(UF_CEL len)
{
    UF *uf = (UF *)malloc(sizeof(UF));
    uf->id = (UF_CEL *)malloc(len * sizeof(UF_CEL));
    uf->w = (UF_CEL *)malloc(len * sizeof(UF_CEL));
    uf->len = len;

    UF_CEL i;
    for (i = 0; i < len; i++)
    {
        uf->id[i] = i;
    }

    for (i = 0; i < len; i++)
    {
        uf->w[i] = 1;
    }

    return uf;
}

void UF_free(UF *uf)
{
    free(uf->id);
    free(uf->w);
    free(uf);
}

void UF_union(UF *uf, UF_CEL a, UF_CEL b)
{
    a = UF_find(uf, a);
    b = UF_find(uf, b);

    if (a == b) return;

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

int UF_connected(UF *uf, UF_CEL a, UF_CEL b)
{
    return (UF_find(uf, a) == UF_find(uf, b));
}

UF_CEL UF_find(UF *uf, UF_CEL f)
{
    while (f != uf->id[f])
    {
        uf->id[f] = uf->id[uf->id[f]]; // Path halving
        f = uf->id[f];
    }
    return uf->id[f];
}