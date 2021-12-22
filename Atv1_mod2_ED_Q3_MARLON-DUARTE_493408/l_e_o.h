#include <stdio.h>
#include <stdlib.h>
#ifndef L_E_O_H_INCLUDED
#define L_E_O_H_INCLUDED
#define TRUE 1
#define FALSE 0

int *vetor, tam, posicao;

void create(int n);             //feito
int add(int valor, int espaco); //feito
int remove_item(int chave);     //feito
int size_lista();               //feito
int linearSearch(int chave);    //feito
int bynarySearch(int chave);             //
int isFull();                   //feito
int isempty();                  //feito
int clear_vetor();              //
void print_all();               //feito


#endif // L_E_O_H_INCLUDED
