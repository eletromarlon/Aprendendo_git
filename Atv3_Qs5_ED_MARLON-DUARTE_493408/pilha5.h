//
// Created by Marlon Duarte on 21/01/2021.
//
#include <stdio.h>
#include <stdlib.h>

struct NO{
    int num;
    struct NO *topo;
};
typedef struct NO node;

int tam;

int menu(void);
void inicia(node *PILHA);
void opcao(node *PILHA, int op);
void exibe(node *PILHA);
void libera(node *PILHA);
void push(node *PILHA);
node *pop(node *PILHA);
