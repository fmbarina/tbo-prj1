#ifndef ARESTA_H_
#define ARESTA_H_



#include "../headers/aresta.h"


typedef struct aresta_st Aresta;
typedef struct vetorAresta_st vetorAresta;

Aresta *aresta_init(Posicao* a, Posicao* b);

Posicao* aresta_getA(Aresta *aresta);

Posicao* aresta_getB(Aresta *aresta);

float aresta_getDist(Aresta *aresta);

void aresta_libera(Aresta *aresta);


/**
 * comeco do vetor de aresta
 * 
 */
#include "../headers/vetor.h"
vetorAresta* vetorAresta_init(Vetor* posicoes);
void vetorAresta_sort(vetorAresta* vetor);
Aresta* vetorAresta_get_Index(vetorAresta* vetor, int index);
int vetorAresta_get_Qtd(vetorAresta* vetor);
void vetorAresta_libera(vetorAresta* vetor);



#endif /* ARESTA_H_ */