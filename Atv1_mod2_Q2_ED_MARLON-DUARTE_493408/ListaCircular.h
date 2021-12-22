#include <stdio.h>
#include <stdlib.h>
#include "No.h"


/*struct no{
    int valor;
    struct no *anterior;
    struct no *proximo;
 } ;*/

//typedef struct no No;

typedef struct {
     No *inicio;
     No *fim;
     int tamanho;
} ListaDuplamenteEncadeada;

ListaDuplamenteEncadeada* create();

int add(ListaDuplamenteEncadeada* lista, int valor);

int pop(ListaDuplamenteEncadeada *lista, int chave);

int isEmpty(ListaDuplamenteEncadeada* lista);

void printListaEncadeada(ListaDuplamenteEncadeada* lista);


void printAll (ListaDuplamenteEncadeada* l);

