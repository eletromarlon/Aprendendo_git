#ifndef TREE_BIN_H_INCLUDED
#define TREE_BIN_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define LADO_ESQ 0
#define LADO_DIR 1
#define false 0
#define true 1

typedef struct no{
	char valor;
	struct no *filhoEsquerda;
	struct no *filhoDireita;
 } No;


typedef struct {
	No *raiz;
} ArvoreBinaria;

ArvoreBinaria *criar();

No *criarRaiz(ArvoreBinaria *arvore, char valor);

No *add(int lado, No *v, char w);

int size_tree();

int is_empty(ArvoreBinaria *arvore);

void pre_ordem (ArvoreBinaria *arvore);

void em_ordem(ArvoreBinaria *arvore);

void pos_ordem(ArvoreBinaria *arvore);

int find_tree(ArvoreBinaria *arvore, char valor);

void clear(ArvoreBinaria *arvore);

#endif // TREE_BIN_H_INCLUDED
