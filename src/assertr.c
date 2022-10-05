#include "../headers/assertr.h"

#include <stdio.h>
#include <stdlib.h>

int assertr(int cond, char *err)
{
    if (!cond)
        printf("\nASSERTR: %s\n", err);
    return (!cond);
}

void assertx(int cond, char *err)
{
    if (!cond)
    {
        printf("\nASSERTX: %s\n", err);
        exit(1);
    }
}