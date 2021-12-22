#ifndef LISTA_DUPLAMENTE_ENCADEADA_CIRCULAR_H_INCLUDED
#define LISTA_DUPLAMENTE_ENCADEADA_CIRCULAR_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

struct no{
    int valor;
    struct no *anterior;
    struct no *proximo;
 } ;

typedef struct no No;

typedef struct {
     No *inicio;
     No *fim;
     int tamanho;
} lista_d_e_c;


lista_d_e_c *create();
//add();
//remove_p();
//size_p();
//find_p();
//isEmpty();
//clear_p();


#endif // LISTA_DUPLAMENTE_ENCADEADA_CIRCULAR_H_INCLUDED
