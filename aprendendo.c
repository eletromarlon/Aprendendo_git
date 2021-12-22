#include <stdio.h>
#include <stdlib.h>
#define maxtam 100

typedef struct {
    int item[maxtam];
    int topo;
} Pilha;

void PilhaInicia (Pilha *p){//p esta acessando o topo e inserindo -1
    p->topo = -1;
}

int PilhaVazia (Pilha *p){
    if (p->topo = -1)
        return 1;
    else
        return 0;
}

int PilhaCheia (Pilha *p){
    if (p->topo == (maxtam-1))
        return 1;
    else
        return 0;
}

void PilhaPush (Pilha *p, int x){
    if (PilhaCheia(p) == 1) {
        printf("\nERRO! Pilha cheia\n");
    } else {
        p->topo++;
        p->item[p->topo] = x;

    }
}

int PilhaPop (Pilha *p){
    int x;
    if (PilhaVazia(p) == 1)
        printf("\nERRO! Pilha vazia\n");
    else {
        x = p->item[p->topo];
        p->topo--;
        return x;
    }
}

int main (){
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    PilhaInicia(p);
    PilhaPush(p, 1);

    printf("Valor no topo %d", p->item[p->topo]);
    return 0;
}
