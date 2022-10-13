#include "aresta.h"


// TIPO ARESTA (estatico e usado dentro de vetor de arestas)
// não pode ser acessado fora desse arquivo

typedef struct aresta_st Aresta;

static Aresta *aresta_init(Vertice* a, Vertice* b);

static Vertice* aresta_getA(Aresta *aresta);

static Vertice* aresta_getB(Aresta *aresta);

static float aresta_getDist(Aresta *aresta);

static void aresta_libera(Aresta *aresta);

struct aresta_st
{
    Vertice* a;
    Vertice* b;
    float dist;
};

static Aresta *aresta_init(Vertice* a, Vertice* b){
    Aresta* aresta = (Aresta*)malloc(sizeof(Aresta));
    aresta->a = a;
    aresta->b = b;
    aresta->dist =vertice_dist(a,b);

    return aresta;
}

static Vertice* aresta_getA(Aresta *aresta){
    return aresta->a;
}

static Vertice* aresta_getB(Aresta *aresta){
    return aresta->b;
}

static float aresta_getDist(Aresta *aresta){
    return aresta->dist;
}

static void aresta_libera(Aresta *aresta){
    free(aresta);
}

/**
 * comeco do vetor de aresta
 * usado em mst e tsp
 */

struct vetorAresta_st{
    Aresta** vet;
    long int qtd;
};

VetorAresta* vetoraresta_init(Vetor* posicoes){
    VetorAresta* vetor = (VetorAresta*)malloc(sizeof(VetorAresta));

    //quantidade de arestas eh uma PA: N(N-1)/2?
    int qtdPosicoes = vetor_qtd_elementos(posicoes); 
    vetor->qtd = ((qtdPosicoes*(qtdPosicoes-1))/2)+1;

    vetor->vet = (Aresta**)malloc(sizeof(Aresta*) * vetor->qtd);


    int i=0 , j=0, k = 0;
    //inicializa as arestas da "Diagonal Principal pra cima"
    for(i =0; i < qtdPosicoes; i++){

        assertx(k < vetor->qtd || i== qtdPosicoes-1, "Index do vetor de aresta ultrapassou limite nas linhas");

        for(j = i+1; j < qtdPosicoes; j++){
            assertx(k < vetor->qtd, "Index do vetor de aresta ultrapassou limite nas colunas");
            /**
             * Nao eh possivel obter index do vetor de aresta de forma linear ao vetor posicoes
             * O k vai ser o index de cada vetor
             */
            Aresta* a = aresta_init(vetor_get_index(posicoes,i), vetor_get_index(posicoes,j));
            vetor->vet[k] = a;

            k++;
            
        }
    }

    //assertx(k == vetor->qtd, "Index do vetor de aresta ultrapassou limite Apos loop");


    return vetor;

}

static int compara(const void* a, const void* b){
    if (aresta_getDist((Aresta*)a) > aresta_getDist((Aresta*)b)) {
      return 1;
   } else if (aresta_getDist((Aresta*)a) < aresta_getDist((Aresta*)b)) {
      return -1;
   } else {
      return 0;
   }
}

void vetoraresta_sort(VetorAresta* vetor){
    qsort(vetor->vet,(size_t)vetor->qtd,sizeof(Aresta*),compara);
}

Aresta* vetoraresta_get_Index(VetorAresta* vetor, int index){
    return vetor->vet[index];
}

int vetoraresta_get_Qtd(VetorAresta* vetor){
    return vetor->qtd;
}

void vetoraresta_libera(VetorAresta* vetor){
    int i;

    assertx(vetor != NULL, "vetor vazio");

    for(i = 0; i < vetor->qtd; i++){
        if(vetor->vet[i] != NULL)
            aresta_libera(vetor->vet[i]);
    }
    free(vetor->vet);
    free(vetor);
}