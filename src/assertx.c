#include "assertx.h"

#include <stdio.h>
#include <stdlib.h>

void assertx(int cond, char *err)
{
    if (!cond)
    {
        printf("\nASSERTX: %s\n", err);
        exit(1);
    }
}