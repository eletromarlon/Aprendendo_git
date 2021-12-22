#ifndef ABB_H_INCLUDED
#define ABB_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct arvore_binaria {
   int valor;
   struct arvore_binaria *esq;
   struct arvore_binaria *dir;
} arvore_binaria;

arvore_binaria* create ();

arvore_binaria* retirar (arvore_binaria *a, int v);

void clear (arvore_binaria *arv);

arvore_binaria* add (arvore_binaria *a, int v);

void pre_ordem (arvore_binaria *arv);

void in_ordem (arvore_binaria *arv);

void pos_ordem (arvore_binaria *arv);

int find (arvore_binaria *a, int v);

#endif // ABB_H_INCLUDED
