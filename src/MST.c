#include "../headers/MST.h"

struct mst_st
{
    VetorAresta* arestasDaArvore;
    /* TODO: Como guardar conexoes reais? Mat de adjac, lista... */
    /* TODO: Guardar logica de conexao em um UF */
};

MST* mst_init(){
    MST* nova = malloc(sizeof(MST));
    nova->arestasDaArvore = NULL;
    return nova;
}

void mst_kruskal(MST* mst)
{
    // TODO: isso
}

