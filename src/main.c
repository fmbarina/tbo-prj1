#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "TSP.h"
#include "assertr.h"
#include "file_op.h"

TSP *make_tsp(FILE *tsp_f);

FILE *make_output(TSP *tsp, char *extension, char *section_name);

int main(int argc, char *argv[])
{
    assertx(argc >= 2, "Faltando argumentos");

    FILE *tsp_f = file_open(argv[1], "r");

    /* Create TSP */
    TSP *tsp = make_tsp(tsp_f);

    /* Prepare output files */
    FILE *mst_f = make_output(tsp, "mst", "MST_SECTION");
    FILE *tou_f = make_output(tsp, "tour", "TOUR_SECTION");

    TSP_preenche_vetor_pos(tsp, tsp_f);
    TSP_preenche_vetarestas(tsp);

    fprintf(mst_f, "EOF\n");
    fprintf(tou_f, "EOF"); /* !newline */

    /* Close files */
    fclose(tsp_f);
    fclose(mst_f);
    fclose(tou_f);

    /* Free memory */
    TSP_free(tsp);

    return 0;
}

TSP *make_tsp(FILE *tsp_f)
{
    /* Get TSP problem data, skip the useless bits */
    char *name = file_read_data(tsp_f); /* NAME */
    file_skip_data(tsp_f);              /* COMMENT */
    file_skip_data(tsp_f);              /* TYPE */
    char *dim = file_read_data(tsp_f);  /* DIMENSION */
    file_skip_data(tsp_f);              /* EDGE_WEIGHT_TYPE */
    file_skip_data(tsp_f);              /* NODE_COORD_SECTION */

    /* Cria TSP* */
    TSP *tsp = TSP_init(name, atoi(dim));

    free(name);
    free(dim);

    return tsp;
}

FILE *make_output(TSP *tsp, char *extension, char *section_name)
{
    long num = strlen(TSP_get_name(tsp)) + strlen(extension) + 1;
    char path[num];
    snprintf(path, num, "%s.%s", TSP_get_name(tsp), extension);

    FILE *out_f = file_open(path, "w");

    /* https://stackoverflow.com/questions/8257714 */
    num = TSP_get_vertices(tsp);
    char dim[(int)((ceil(log10(num)) + 1) * sizeof(char))];
    sprintf(dim, "%li", num);

    file_write_template(out_f, TSP_get_name(tsp), dim, section_name);

    return out_f;
}
