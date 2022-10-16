#include <stdio.h>

#include "UF.h"
#include "assertr.h"

int main()
{
    UF* uf = UF_init(10);

    UF_print(uf);

    UF_union(uf, 0, 1);
    UF_union(uf, 0, 2);
    UF_union(uf, 1, 3);
    UF_union(uf, 3, 4);

    UF_print(uf);

    UF_union(uf, 5, 6);
    UF_union(uf, 7, 6);
    UF_union(uf, 9, 7);
    UF_union(uf, 7, 8);

    UF_print(uf);
    
    UF_union(uf, 2, 6);   

    assertr(UF_connected(uf, 0, 1), "0 e 1 não estão conectados");
    assertr(UF_connected(uf, 1, 2), "1 e 2 não estão conectados");
    assertr(UF_connected(uf, 2, 3), "2 e 3 não estão conectados");
    assertr(UF_connected(uf, 3, 4), "3 e 4 não estão conectados");
    assertr(UF_connected(uf, 4, 5), "4 e 5 não estão conectados");
    assertr(UF_connected(uf, 5, 6), "5 e 6 não estão conectados");
    assertr(UF_connected(uf, 6, 7), "6 e 7 não estão conectados");
    assertr(UF_connected(uf, 7, 8), "7 e 8 não estão conectados");
    assertr(UF_connected(uf, 8, 9), "8 e 9 não estão conectados");

    UF_print(uf);

    UF_free(uf);
    
    return 0;
}