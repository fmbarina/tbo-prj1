#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "TSP.h"
#include "adj_matrix.h"
#include "assertr.h"
#include "file_op.h"
#include "tour.h"

TSP *make_tsp(FILE *tsp_f);

FILE *make_output(TSP *tsp, char *extension, char *type);

int main(int argc, char *argv[])
{
    assertx(argc >= 2, "Faltando argumentos");
    FILE *tsp_f = file_open(argv[1], "r");

    /* Create TSP */
    TSP *tsp = make_tsp(tsp_f);

    /* Prepare output files */
    FILE *mst_f = make_output(tsp, "mst", "MST");
    FILE *tou_f = make_output(tsp, "tour", "TOUR");

    /* Read and solve TSP */
    TSP_preenche_vetor_pos(tsp, tsp_f);
    TSP_preenche_vetarestas(tsp);
    TSP_kruskal(tsp);
    TSP_tour(tsp);

    /* Write main output */
    adj_mat_fprint(TSP_get_adj_mat(tsp), mst_f);
    tour_fprint(TSP_get_tour(tsp), tou_f);

    /* Finish and close output files */
    fprintf(mst_f, "EOF\n");
    fprintf(tou_f, "EOF\n"); /* TODO:\n? Ver arquivos, inconsistente(otimo?) */

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
    TSP *tsp = TSP_init(name, atol(dim));

    free(name);
    free(dim);

    return tsp;
}

FILE *make_output(TSP *tsp, char *extension, char *type)
{
    long num = strlen(TSP_get_name(tsp)) + strlen(extension) + 2;
    char path[num];
    snprintf(path, num, "%s.%s", TSP_get_name(tsp), extension);

    FILE *out_f = file_open(path, "w");

    /* Obrigado a: https://stackoverflow.com/questions/8257714 */
    num = TSP_get_vertices(tsp);
    char dim[(int)((ceil(log10(num)) + 1) * sizeof(char))];
    sprintf(dim, "%li", num);

    file_write_template(out_f, TSP_get_name(tsp), dim, type);

    return out_f;
}
