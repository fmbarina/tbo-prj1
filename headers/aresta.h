#ifndef ARESTA_H_
#define ARESTA_H_

#include "../headers/vetor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/posicao.h"
#include "../headers/vetor.h"
#include "../headers/assertr.h"


typedef struct vetorAresta_st VetorAresta;
/**
 * comeco do vetor de aresta
 * 
 */

VetorAresta* vetorAresta_init(Vetor* posicoes);
void vetoraresta_sort(VetorAresta* vetor);

/* Tipo aresta eh estático, manter assim? Estático ocasiona problema nessa funcao*/
//Aresta* vetoraresta_get_Index(VetorAresta* vetor, int index);

int vetoraresta_get_Qtd(VetorAresta* vetor);
void vetoraresta_libera(VetorAresta* vetor);



#endif /* ARESTA_H_ */