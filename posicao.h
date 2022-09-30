#ifndef POSICAO_H
#define POSICAO_H

typedef struct posicao Posicao;

Posicao* inicializaPosicao(float x, float y);
float GetXPosicao(Posicao* posicao);
float GetYPosicao(Posicao* posicao);
float distanciaPosicao(Posicao* a, Posicao* b);
void imprimePosicao(Posicao* posicao);
void liberaPosicao(Posicao* posicao);

Posicao*  alocaNPosicoes(int qtd);
#endif