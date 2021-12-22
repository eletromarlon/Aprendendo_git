#ifndef ITENS_AVL_H_INCLUDED
#define ITENS_AVL_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int elemento;
	int fator_b;

	struct node* esq;
	struct node* dir;

}Tnode;

int altura_AVL(Tnode *a);
int calcula_FB(Tnode *a);
Tnode* rot_simples_esquerda(Tnode* a);
Tnode* rot_simples_direita(Tnode *a);
Tnode* balanceamento(Tnode* a);
Tnode* inserir_avl(Tnode* a, int elemento);
void imprime_avl(Tnode* a);

#endif // ITENS_AVL_H_INCLUDED
