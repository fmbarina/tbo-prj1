#include "vetor.h"

#include <stdio.h>
#include <stdlib.h>

#include "vertice.h"

struct vetor_st
{
    Vertice **itens;
    int qtd;
};

Vetor *vetor_init(int qtd)
{
    Vetor *vet = (Vetor *)malloc(sizeof(Vetor));
    vet->qtd = qtd;
    vet->itens = (Vertice **)malloc(qtd * sizeof(Vertice *));

    int i;
    for (i = 0; i < qtd; i++)
        vet->itens[i] = NULL;

    return vet;
}

Vertice *vetor_get_index(Vetor *vetor, int index)
{
    return vetor->itens[index];
}

void vetor_set_index(Vetor *vetor, Vertice *item, int index)
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
        if (vetor->itens[i])
            vertice_imprime(vetor->itens[i]);

    printf("\n");
}

void vetor_libera(Vetor *vetor)
{
    for (int i = 0; i < vetor_qtd_elementos(vetor); i++)
        vertice_free(vetor_get_index(vetor, i));

    free(vetor->itens);
    free(vetor);
}