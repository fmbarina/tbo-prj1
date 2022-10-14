#include "vetor.h"

#include <stdio.h>
#include <stdlib.h>

#include "vertex.h"

struct vetor_st
{
    Vertex **itens;
    int qtd;
};

Vetor *vetor_init(int qtd)
{
    Vetor *vet = (Vetor *)malloc(sizeof(Vetor));
    vet->qtd = qtd;
    vet->itens = (Vertex **)malloc(qtd * sizeof(Vertex *));

    long i;
    for (i = 0; i < qtd; i++)
        vet->itens[i] = NULL;

    return vet;
}

Vertex *vetor_get_index(Vetor *vetor, int index)
{
    return vetor->itens[index];
}

void vetor_set_index(Vetor *vetor, Vertex *item, int index)
{
    vetor->itens[index] = NULL;
    vetor->itens[index] = item;
}

int vetor_qtd_elementos(Vetor *vetor)
{
    return vetor->qtd;
}

void vetor_imprime(Vetor *vetor)
{
    for (int i = 0; i < vetor->qtd; i++)
        if (vetor->itens[i]) vertex_imprime(vetor->itens[i]);

    printf("\n");
}

void vetor_libera(Vetor *vetor)
{
    for (int i = 0; i < vetor_qtd_elementos(vetor); i++)
        vertex_free(vetor_get_index(vetor, i));

    free(vetor->itens);
    free(vetor);
}