#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/arquivo.h"
#include "../headers/assertr.h"
#include "TSP.h"

int main(int argc, char *argv[])
{
    assertx(argc >= 2, "Faltando argumentos");

    FILE *tsp_f = fopen(argv[1], "r");
    assertx(tsp_f != NULL, "Nao foi possivel abrir o arquivo");

    /* Get TSP problem data, skip the useless bits */
    char *name = arq_le_dado(tsp_f); /* NAME */
    arq_pula_dado(tsp_f);            /* COMMENT */
    arq_pula_dado(tsp_f);            /* TYPE */
    char *dim = arq_le_dado(tsp_f);  /* DIMENSION */
    arq_pula_dado(tsp_f);            /* EDGE_WEIGHT_TYPE */
    arq_pula_dado(tsp_f);            /* NODE_COORD_SECTION */

    /* Cria TSP* */
    TSP* tsp = TSP_init(name,atoi(dim));

    /* Prepare output files */
    char *name_buf = strdup(name);
    FILE *mst_f = fopen(strcat(name_buf, ".mst"), "w");
    arq_esc_header(mst_f, name, dim);
    fprintf(mst_f, "MST_SECTION\n");
    
    name_buf = strcpy(name_buf, name);
    FILE *tou_f = fopen(strcat(name_buf, ".tour"), "w");
    arq_esc_header(tou_f, name, dim);
    fprintf(tou_f, "TOUR_SECTION\n");
    

    /* Read nodes 
    int i;
    for (i = 0; i < atoi(dim); i++)
    {
        Posicao *pos = arq_le_pos(tsp_f);
        posicao_imprime(pos); // TODO: algo util de verdade
        printf("\n");
        posicao_libera(pos);
    }
    já existe essa função::
    */
    TSP_preenche_vetor_pos(tsp,tsp_f);
    TSP_preenche_vet_dist(tsp);

    fprintf(mst_f, "EOF\n");
    fprintf(tou_f, "EOF"); /* !newline */

    /* Close files */
    fclose(tsp_f);
    fclose(mst_f);
    fclose(tou_f);

    /* Free memory */
    TSP_libera(tsp);
    free(name_buf);
    free(name);
    free(dim);

    return 0;
}