#ifndef TOUR_H_
#define TOUR_H_

#include <stdbool.h>

typedef struct tour_st Tour;

Tour* tour_init(long qtd);

void tour_free(Tour* t);

int tour_get_parent(Tour* t);

int tour_get_visited(Tour* t);

bool tour_get_finished(Tour* t);

int tour_get_component(Tour* t);

#endif /* TOUR_H_ */