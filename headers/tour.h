#ifndef TOUR_H_
#define TOUR_H_

#include <stdbool.h>

#include "adj_matrix.h"

typedef struct tour_st Tour;

Tour *tour_init(int size);

void tour_free(Tour *t);

void tour_DFS(Tour *t, Adj_matrix *adj, int vertex_id);

void tour_fprint(Tour *t, FILE *f);

#endif /* TOUR_H_ */