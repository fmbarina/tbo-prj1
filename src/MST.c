#include "MST.h"
#include "UF.h"
#include "adj_matrix.h"

struct mst_st
{
    UF* qw_union;
    Adj_matrix* adj_mat;
};

MST* MST_init(unsigned long len){
    MST* mst = malloc(sizeof(MST));
    mst->qw_union = UF_init(len);
    mst->adj_mat = adj_mat_init(len);
    return mst;
}

void MST_libera(MST* mst){
    adj_mat_free(mst->adj_mat);
    UF_free(mst->qw_union);
    free(mst);
}