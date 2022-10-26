#include "file_op.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "assertx.h"
#include "common.h"
#include "vertex.h"

#define MAX_LEN 128

FILE *file_open(char *path, char *mode)
{
    FILE *tsp_f = fopen(path, mode);
    assertx(tsp_f != NULL, "Nao foi possivel abrir o arquivo");
    return tsp_f;
}

char *file_read_data(FILE *f)
{
    // TODO: fix this shit
    char *read = (char *)malloc(MAX_LEN * sizeof(char));
    assertx(fscanf(f, "%*[^:]: %" STR(MAX_LEN) "[^\n]%*c", read),
            "read_data: não foi possivel ler dado");
    return read;
}

void file_skip_data(FILE *f)
{
    fscanf(f, "%*[^\n]%*c"); // Ignore this warning
    return;
}

Vertex *file_read_vertex(FILE *f)
{
    IDT id;
    float x = 0, y = 0;
    assertx(fscanf(f, IDF " %f %f%*[^\n]%*c", &id, &x, &y) == 3,
            "read_vertex: nao foi possivel ler vertex");
    // ID - 1 para index começar em 0
    return vertex_init(id - 1, x, y);
}

void file_write_template(FILE *f, char *name, char *dim, char *type)
{
    fprintf(f, "NAME: %s\n", name);
    fprintf(f, "TYPE: %s\n", type);
    fprintf(f, "DIMENSION: %s\n", dim);
    fprintf(f, "%s_SECTION\n", type);
}