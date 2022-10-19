#include "aresta.h"

static void aresta_init(Vertex *a, Vertex *b, Aresta *aresta)
{
    aresta->a = a;
    aresta->b = b;
    aresta->dist = vertex_dist(a, b);
}

Vertex *aresta_getA(Aresta *aresta)
{
    return aresta->a;
}

Vertex *aresta_getB(Aresta *aresta)
{
    return aresta->b;
}

float aresta_getDist(Aresta *aresta)
{
    return aresta->dist;
}

void aresta_print(Aresta *aresta)
{
    printf("[ ");
    vertex_print(aresta->a);
    printf("; ");
    vertex_print(aresta->b);
    printf("; ");
    printf("%f ", aresta->dist);
    printf("] \n");
}

/* ------------------------------------------------------------------------ */

struct vetorAresta_st
{
    Aresta *vet;
    long int qtd;
};

VetorAresta *vetoraresta_init(Vetor *posicoes)
{
    VetorAresta *vetor = (VetorAresta *)malloc(sizeof(VetorAresta));

    // quantidade de arestas eh uma PA: N(N-1)/2?
    long vertices = vetor_qtd_elementos(posicoes);
    vetor->qtd = ((vertices * (vertices - 1)) / 2);
    vetor->vet = (Aresta *)malloc(sizeof(Aresta) * vetor->qtd);

    long i = 0, j = 0, k = 0;
    // inicializa as arestas da "Diagonal Principal pra cima"
    for (i = 0; i < vertices; i++)
    {

        assertx(k < vetor->qtd || i == vertices - 1,
                "Index do vetor de aresta ultrapassou limite de linhas");

        for (j = i + 1; j < vertices; j++)
        {
            assertx(k < vetor->qtd,
                    "Index do vetor de aresta ultrapassou limite de colunas");
            /**
             * Nao eh possivel obter index do vetor de aresta de forma linear
             * ao vetor posicoes O k vai ser o index de cada vetor
             */

            aresta_init(vetor_get_index(posicoes, i),
                        vetor_get_index(posicoes, j), ((vetor->vet) + k));
            k++;
        }
    }

    // TODO: que isso mesmo?
    // assertx(k == vetor->qtd, "Index do vetor de aresta ultrapassou limite
    // Apos loop");

    return vetor;
}

void vetoraresta_free(VetorAresta *vetor)
{
    assertx(vetor != NULL, "vetor vazio");
    free(vetor->vet);
    free(vetor);
}

static int compara(const void *a, const void *b)
{
    /**
     * Passa o que esta apontado por aresta (passar como argumento o endereco
     * da aresta)
     */
    if (((Aresta *)a)->dist > ((Aresta *)b)->dist) return 1;
    else if (((Aresta *)a)->dist < ((Aresta *)b)->dist) return -1;
    else return 0;

}

void vetoraresta_sort(VetorAresta *vetor)
{
    qsort(vetor->vet, vetor->qtd, sizeof(Aresta), compara);
}

void vetoraresta_print(VetorAresta *vetor)
{
    printf("{ ");
    long i;
    for (i = 0; i < vetor->qtd; i++)
        aresta_print((vetor->vet) + i);
    printf("} ");
}

Aresta *vetoraresta_get_index(VetorAresta *vetor, long index)
{
    return ((vetor->vet) + index);
}

long vetoraresta_get_qtd(VetorAresta *vetor)
{
    return vetor->qtd;
}