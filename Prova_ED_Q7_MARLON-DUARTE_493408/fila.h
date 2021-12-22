#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
int *vetor, fim;    //Comentário no todo das função em "fila.c"
void comeca(int *vetor, int espaco);
int vazio(int *vetor);
int cheio(int *vetor, int espaco);
void insere(int *vetor, int x, int espaco);
int tamanho(int *vetor);
int retira(int *vetor);
void imprime(int *vetor);


#endif // FILA_H_INCLUDED
