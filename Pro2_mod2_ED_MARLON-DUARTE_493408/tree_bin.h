#include <stdio.h>
#include <stdlib.h>

typedef struct arvore_binaria {
   int info;
   struct arvore_binaria *esq;
   struct arvore_binaria *dir;
} arvore_binaria;

arvore_binaria* cria_arv_vazia ();

arvore_binaria* Remover (arvore_binaria *a, int v);

void destroi_arv (arvore_binaria *arv);

arvore_binaria* inserir (arvore_binaria *a, int v);

arvore_binaria* constroi_arv (int elem, arvore_binaria *esq, arvore_binaria *dir);

int min (arvore_binaria *a);

int max (arvore_binaria *a);

void imprime_decrescente (arvore_binaria *a);

int maior_ramo (arvore_binaria *a);

void pre_ordem (arvore_binaria *arv);

void in_ordem (arvore_binaria *arv);

void pos_ordem (arvore_binaria *arv);

int buscar (arvore_binaria *a, int v);

