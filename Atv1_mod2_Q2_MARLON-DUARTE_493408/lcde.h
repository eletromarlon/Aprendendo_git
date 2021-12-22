#include <stdio.h>
#include <stdlib.h>
#ifndef LCDE_H_INCLUDED
#define LCDE_H_INCLUDED
#define TRUE 1
#define FALSE 0

typedef struct {
    int valor;
    struct no *anterior;
    struct no *proximo;
}no;

typedef struct {
	no *inicio;
	no *fim;
    int tamanho;
}lista_cde;

lista_cde *create ();
int add_item(lista_cde *lista, int valor);
int remove_item(lista_cde *lista, int chave);
int size_item(lista_cde *lista);
int find_item(lista_cde *lista, int valor);
int isempty(lista_cde *lista);
int clear_item(lista_cde *lista);
int printAll (lista_cde *l);

#endif // LCDE_H_INCLUDED
