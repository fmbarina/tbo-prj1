#include "TSP.h"

struct tsp
{
    char* nome;
    /*nome só para deixar ai (matriz de localizacoes) */
    TipoLocalizador** localizacoes;
    int nVertices;
};


/**
 * @brief Inicia a estrutura para guardar dados da TSP
 * 
 * @param nome - char*
 * @param numVertices - int
 * @return TSP* 
 */
TSP* initTSP(char* nome, int numVertices){
    TSP* tsp = (TSP*)malloc(sizeof(TSP));

   // tsp->localizacoes = initLocalizador(numVertices);

    tsp->nome = strdup(nome);
    tsp->nVertices = numVertices;
    return tsp;
}

void addLocalTSP(TSP* tsp,TipoLocalizador* local){
    
}