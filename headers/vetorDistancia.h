#ifndef VETORDISTANCIA_H_
#define VETORDISTANCIA_H_

#include <stdio.h>
#include <stdlib.h>

#include "TSP.h"

typedef struct vetordist_st VetorDistancia;

VetorDistancia *vetordist_init(Vetor *vp);

void vetordist_preenche(VetorDistancia *vd, Vetor *vp);

void vetordist_imprime(VetorDistancia* vd);

void vetordist_libera(VetorDistancia *vd);

#endif /* VETORDISTANCIA_H_ */