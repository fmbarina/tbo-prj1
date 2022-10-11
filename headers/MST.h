#ifndef MST_H_
#define MST_H_

#include "aresta.h"

typedef struct mst_st MST;

MST* mst_init();

void mst_kruskal(MST* mst);

#endif /* MST_H_ */