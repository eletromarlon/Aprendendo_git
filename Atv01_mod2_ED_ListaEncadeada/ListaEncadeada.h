#ifndef LISTAENCADEADA_H_INCLUDED
#define LISTAENCADEADA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "No.h"

typedef struct {
	 No *inicio;
	 No *fim;
	 int tamanho;
} ListaEncadeada;

ListaEncadeada* create();

int add(ListaEncadeada* lista, int valor);

int remover(ListaEncadeada *lista, int chave);

int size_p(ListaEncadeada *lista);//Atividade 1 mod2

int finder(ListaEncadeada* lista, int valor);

int isEmpty(ListaEncadeada* lista);

void printListaEncadeada(ListaEncadeada* listaEncadeada);

void clear_p(ListaEncadeada* lista);


#endif // LISTAENCADEADA_H_INCLUDED
