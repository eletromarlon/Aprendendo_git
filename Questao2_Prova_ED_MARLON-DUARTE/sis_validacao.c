#include "sis_validacao.h"
int k=0;

item criar_repositorio(item *p){
    p = (item*) malloc(sizeof(item));
    return p;
}

void adicionar(item *p, int cod, float valor){
    p = (item*) malloc (sizeof(item));
    p[k].codigo = cod;
    p[k].valor = valor;
    k++;
}

void imprimir_repositorio(item *p){
    printf("Valor em codigo %x e em valor %x", &p[0].codigo,&p[0].valor);
}


int tamanho(){
    return k;
}

int esta_cheio(){
    if (k>0)
        return 1;
    else
        return 0;
}

int esta_vazio(){
    if (k<1)
        return 1;
    else
        return 0;
}
