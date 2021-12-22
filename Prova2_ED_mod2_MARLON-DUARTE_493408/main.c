#include <stdio.h>
#include <stdlib.h>
#include "ABB.h"

int main(){
    arvore_binaria *a = (arvore_binaria*)malloc(sizeof(arvore_binaria));

    create();

    add(a, 17);
    add(a, 99);
    add(a, 13);
    add(a, 1);
    add(a, 3);
    add(a, 100);
    add(a, 400);


    in_ordem(a);
    printf("\n");
    pos_ordem(a);
    printf("\n");
    pre_ordem(a);

    printf("\nProfundidade de 3 - %d\n", find(a, 3));

    return 0;
}
