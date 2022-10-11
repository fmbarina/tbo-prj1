#include "vetor.h"

#include <stdio.h>
#include <stdlib.h>

#include "posicao.h"

struct vetor_st
{
    Posicao **itens;
    int qtd;
};

Vetor *vetor_init(int qtd)
{
    Vetor *vet = (Vetor *)malloc(sizeof(Vetor));
    vet->qtd = qtd;
    vet->itens = (Posicao **)malloc(qtd * sizeof(Posicao *));

    int i;
    for (i = 0; i < qtd; i++)
        vet->itens[i] = NULL;

    return vet;
}

Posicao *vetor_get_index(Vetor *vetor, int index)
{
    return vetor->itens[index];
}

void vetor_set_index(Vetor *vetor, Posicao *item, int index)
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
            posicao_imprime(vetor->itens[i]);

    printf("\n");
}

void vetor_libera(Vetor *vetor)
{
    for (int i = 0; i < vetor_qtd_elementos(vetor); i++)
        posicao_libera(vetor_get_index(vetor, i));

    free(vetor->itens);
    free(vetor);
}