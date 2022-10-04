#include "../headers/assertr.h"
#include <stdlib.h>
#include <stdio.h>

int assertr(int cond, char* err)
{
    if (!cond)
        printf("\nASSERTR: %s", err);
    return (!cond);
}

void assertx(int cond, char* err)
{
    if (!cond) {
        printf("\nASSERTX: %s", err);
        exit(1);
    }
}