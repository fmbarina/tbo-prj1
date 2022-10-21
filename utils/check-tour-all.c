#include <stdio.h>
#include <stdlib.h>

/* Imprimir partes faltando de um tour 
 * Remover tudo até (incluindo) *_SECTION 
 * Remove EOF(?)
 */

int main(int argc, char* argv[])
{
    int i, t, d;
    
    d = -1;
    t = atoi(argv[1]);

    int* vet = (int*) calloc(t, sizeof(int));

    while (scanf("%d", &d) == 1)
        vet[d-1] = 1;

    for (i = 0; i < t; i++)
        if (!vet[i]) printf("%d\n", i+1);

    return 0;
}