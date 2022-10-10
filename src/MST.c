#include "../headers/MST.h"

struct mst_st
{
    VetorAresta* arestasDaArvore;
};

MST* mst_init(){
    MST* nova = malloc(sizeof(MST));
    nova->arestasDaArvore = NULL;
    return nova;
}