#ifndef CABECALHO_H_INCLUDED
#define CABECALHO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
int *vetor, topo; //Comentários feitos na main
void comeca(int *vetor, int espaco);
int vazio(int *vetor);
int cheio(int *vetor, int espaco);
void insere(int *vetor, int x);
void tamanho(int *vetor);
int retira(int *vetor);
void imprime(int *vetor);
void inverte(int *vetor, int espaco);


#endif // CABECALHO_H_INCLUDED
