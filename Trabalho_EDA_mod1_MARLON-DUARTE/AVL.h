#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct no{
	int elemento;
	int fator_b;

	struct no* esq;
	struct no* dir;

}Tno;

void menu();
int altura_AVL(Tno *a);
int calcula_FB(Tno *a);
Tno* rotacao_simples_esquerda(Tno *a);
Tno* rotacao_simples_diretira(Tno *a);
Tno* balanceamento(Tno* a);
Tno* inserir(Tno* a, int elemento);
void imprime(Tno* a);


#endif // AVL_H_INCLUDED
