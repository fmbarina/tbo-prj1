#include "../headers/arquivo.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/posicao.h"

/* Obrigado a https://stackoverflow.com/questions/47346133 */
#define MAX_LEN 128
#define STR_(X) #X
#define STR(X) STR_(X)

char *arq_le_dado(FILE *f)
{
    char *read = (char *)malloc(MAX_LEN * sizeof(char));
    fscanf(f, "%*[^:]: %" STR(MAX_LEN) "[^\n]%*c", read);
    return read;
}

void arq_pula_dado(FILE *f)
{
    fscanf(f, "%*[^\n]%*c");
    return;
}

Posicao *arq_le_pos(FILE *f)
{
    float x = 0, y = 0;
    fscanf(f, "%*d %f %f%*[^\n]%*c", &x, &y);
    return posicao_init(x, y);
}

void *arq_esc_header(FILE *f, char* name, char* dim)
{
    fprintf(f, "NAME: %s\n", name);
    fprintf(f, "TYPE: TOUR\n");
    fprintf(f, "DIMENSION: %s\n", dim);
}