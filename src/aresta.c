#include "posicao.h"
#include "vetorDistancia.h"

struct vetorAresta{
    Aresta** vet;
};

struct aresta
{
    Posicao* a;
    Posicao* b;
    double dist;
};
