#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Imprimir vertices faltando de um arquivo tour
 * Para um dado problema "problema" com 100 cidades,
 * usar com: ./[programa] 100 <./caminho/para/problema.tour
 */

int main(int argc, char* argv[])
{
    int i, t, d;
    char buf[128];

    d = -1;
    t = atoi(argv[1]);

    int* vet = (int*) calloc(t, sizeof(int));
    
    while (scanf("%128[^\n]%*c", &buf) == 1)
        if (!strcmp(buf, "TOUR_SECTION")) break;

    while (scanf("%d", &d) == 1)
        vet[d-1] = 1;

    for (i = 0; i < t; i++)
        if (!vet[i]) printf("%d\n", i+1);

    return 0;
}