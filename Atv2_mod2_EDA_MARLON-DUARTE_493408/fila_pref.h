#ifndef FILA_PREF_H_INCLUDED
#define FILA_PREF_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>

struct Heap{
    int *vetor;
    int contador;
    int tamanho;
    int tipo_heap; /**0 para heap min e 1 para heap max*/
};

typedef struct Heap Heap;

Heap *criar_heap(int tamanho,int tipo_heap);
void insert(Heap *h, int key);
void heap_acima(Heap *h,int index);
void heap_abaixo(Heap *h, int parent_node);
int PopMin(Heap *h);
int status_fila(Heap *h);



#endif // FILA_PREF_H_INCLUDED
