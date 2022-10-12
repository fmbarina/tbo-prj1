#include "MST.h"
#include "UF.h"

struct mst_st
{
    UF* qw_union;
    // Matrix
};

MST* MST_init(unsigned long int len){
    MST* nova = malloc(sizeof(MST));
    
    nova->qw_union = UF_init(len);


    return nova;
}

void MST_libera(MST* m){
    UF_free(m->qw_union);
    free(m);
}