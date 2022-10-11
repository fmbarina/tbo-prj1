#ifndef UF_H_
#define UF_H_

/* Weighted Quick Union com comp. de caminho */

typedef struct uf_st UF;

UF* UF_init(unsigned long int size);

void UF_free(UF* uf);

void UF_union(UF* uf, unsigned long int a, unsigned long int b);

int UF_connected(UF* uf, unsigned long int a, unsigned long int b);

unsigned long int UF_find(UF* uf, unsigned long int f);

void UF_print(UF* uf);

#endif /* UF_H_ */