#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../headers/arquivo.h"
#include "../headers/assertr.h"
#include "TSP.h"

/** @brief FUNÇÕES DE CABEÇALHO */

/**
 * @brief função para abrir arquivo tsp
 * 
 * @param argv 
 * @return FILE* 
 */
FILE* arq_tsp_abre(char* argv);

FILE* arq_saida_prepara_tour(TSP* tsp);

FILE* arq_saida_prepara_mst(TSP* tsp);


TSP* arq_puxa_tsp(FILE* tsp_f);



/**
 * @brief MAIN
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */

int main(int argc, char *argv[])
{
    assertx(argc >= 2, "Faltando argumentos");

    FILE *tsp_f = arq_tsp_abre(argv[1]);

    TSP* tsp = arq_puxa_tsp(tsp_f);

    
    /* Prepare output files */
    FILE* mst_f = arq_saida_prepara_mst( tsp );
    FILE* tou_f = arq_saida_prepara_tour( tsp );

    TSP_preenche_vetor_pos(tsp,tsp_f);
    TSP_preenche_vetarestas(tsp);

    fprintf(mst_f, "EOF\n");
    fprintf(tou_f, "EOF"); /* !newline */

    /* Close files */
    fclose(tsp_f);
    fclose(mst_f);
    fclose(tou_f);

    /* Free memory */
    //printf("\nLiberando Memoria\n");
    TSP_libera(tsp);


    return 0;
}

FILE* arq_tsp_abre(char* argv){
    FILE* tsp_f; 
    tsp_f = fopen(argv, "r");
    assertx(tsp_f != NULL, "Nao foi possivel abrir o arquivo");
    return tsp_f;
}

TSP* arq_puxa_tsp(FILE* tsp_f){
    /* Get TSP problem data, skip the useless bits */
    char *name = arq_le_dado(tsp_f); /* NAME */
    arq_pula_dado(tsp_f);            /* COMMENT */
    arq_pula_dado(tsp_f);            /* TYPE */
    char *dim = arq_le_dado(tsp_f);  /* DIMENSION */
    arq_pula_dado(tsp_f);            /* EDGE_WEIGHT_TYPE */
    arq_pula_dado(tsp_f);            /* NODE_COORD_SECTION */

    /* Cria TSP* */
    TSP* tsp = TSP_init(name,atoi(dim));

    free(name);
    free(dim);

    return tsp;
}

FILE* arq_saida_prepara_mst(TSP* tsp){
    char name_buf_static[strlen(TSP_get_name(tsp))+5];
    name_buf_static[0]='\0';
    strcat(name_buf_static,TSP_get_name(tsp));
    strcat(name_buf_static, ".mst\0");
    
    FILE *mst_f = fopen(name_buf_static, "w");

    //https://stackoverflow.com/questions/8257714/how-to-convert-an-int-to-string-in-c //
    int num = TSP_get_nvertices(tsp);
    char str[(int)((ceil(log10(num))+1)*sizeof(char))];
    sprintf(str, "%d", num);
    //                                                                                //

    arq_esc_header(mst_f, TSP_get_name(tsp), str);
    fprintf(mst_f, "MST_SECTION\n");
    
    return mst_f;

}

FILE* arq_saida_prepara_tour(TSP* tsp){
    char name_buf_static[strlen(TSP_get_name(tsp))+5];
    name_buf_static[0]='\0';
    strcat(name_buf_static,TSP_get_name(tsp));
    strcat(name_buf_static, ".tour\0");
    
    FILE *tou_f = fopen(name_buf_static, "w");


    //https://stackoverflow.com/questions/8257714/how-to-convert-an-int-to-string-in-c //
    int num = TSP_get_nvertices(tsp);
    char str[(int)((ceil(log10(num))+1)*sizeof(char))];
    sprintf(str, "%d", num);
    //                                                                                //

    arq_esc_header(tou_f, TSP_get_name(tsp), str);

    fprintf(tou_f, "TOUR_SECTION\n");

    return tou_f;
}