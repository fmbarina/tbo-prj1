#include "tour.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
struct tour_st
{
    int parent;
    int visited;
    bool finished;
    int component;
};

static Tour tour_initialize(Tour t, int i)
{
    t.parent=i;
    t.visited = 0;
    t.finished = false;
    t.component = 0;
}

Tour *tour_init(long qtd)
{   
    Tour *vet = malloc(qtd * sizeof(Tour));
    int i;
    for (i = 0; i < qtd; i++){

        vet[i] = tour_initialize(vet[i],i);
    }
    return vet;
}

void tour_free(Tour* t)
{
    free(t);
}

int tour_get_parent(Tour* t)
{
    return t->parent;
}

int tour_get_visited(Tour* t)
{
    return t->visited;
}

bool tour_get_finished(Tour* t)
{
    return t->finished;
}

int tour_get_component(Tour* t)
{
    return t->component;
}

int tour_DFS(Tour v, int counter, int component){
    v.visited = counter;
    v.component = component;
    int i;
    for (i = 0; i < ; i++)
    {
        /* code */
    }
    
}

/*
Prototipo

DFS(Tour* v(vertice?), c??)
{
    v.visitado <- true
    v.componente <- c???????

    int i;
    for (i = v->index???? < vetor_vertice->qtd?; i++)
    {
        if (!Adj_get_val(i, j))
            continue;
        
        Tour* w = vetor_de_tour[]


        if (v.visitado)   

    }   
    
}

*/
