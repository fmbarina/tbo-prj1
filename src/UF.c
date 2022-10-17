#include "UF.h"
#include "assertr.h"
#include <stdio.h>
#include <stdlib.h>

struct uf_st
{
    CEL *id;
    CEL *w;
    CEL len;
};

UF *UF_init(CEL len)
{
    UF *uf = (UF *)malloc(sizeof(UF));
    uf->id = (CEL *)malloc(len * sizeof(CEL));
    uf->w = (CEL*)malloc(len*sizeof(CEL));
    uf->len = len;

    CEL i;
    for (i = 0; i < len; i++){
        uf->id[i] = i;
    }

    for (i = 0; i < len; i++){
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

void UF_union(UF *uf, CEL a, CEL b)
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

int UF_connected(UF *uf, CEL a, CEL b)
{
    return (UF_find(uf, a) == UF_find(uf, b));
}

CEL UF_find(UF *uf, CEL f)
{
    // DEBUG: assertx(uf->id[f] != 52, "AQ");
    while (f != uf->id[f])
    {
        uf->id[f] = uf->id[uf->id[f]]; // Path halving
        f = uf->id[f];
    }

    return uf->id[f];
}

// TODO: remove
// void UF_print(UF *uf)
// {
//     CEL i;
//     for (i = 0; i < uf->len; i++)
//         printf("id[%li] = %li\n", i, uf->id[i]);
// }