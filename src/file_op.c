#include "file_op.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "assertr.h"
#include "vertex.h"

/* Obrigado a https://stackoverflow.com/questions/47346133 */
#define MAX_LEN 128
#define STR_(X) #X
#define STR(X) STR_(X)

FILE *file_open(char *path, char *mode)
{
    FILE *tsp_f = fopen(path, mode);
    assertx(tsp_f != NULL, "Nao foi possivel abrir o arquivo");
    return tsp_f;
}

char *file_read_data(FILE *f)
{
    char *read = (char *)malloc(MAX_LEN * sizeof(char));
    fscanf(f, "%*[^:]: %" STR(MAX_LEN) "[^\n]%*c", read);
    return read;
}

void file_skip_data(FILE *f)
{
    fscanf(f, "%*[^\n]%*c");
    return;
}

Vertex *file_read_vertex(FILE *f)
{
    long id;
    float x = 0, y = 0;
    fscanf(f, "%li %f %f%*[^\n]%*c", &id, &x, &y);
    // ID - 1 para index começar em 0
    return vertex_init(id-1, x, y);
}

void file_write_template(FILE *f, char *name, char *dim, char *section_name)
{
    fprintf(f, "NAME: %s\n", name);
    fprintf(f, "TYPE: TOUR\n");
    fprintf(f, "DIMENSION: %s\n", dim);
    fprintf(f, "%s\n", section_name);
}