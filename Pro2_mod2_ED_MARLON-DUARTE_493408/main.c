#include <stdio.h>
#include <stdlib.h>
#include "tree_bin.h"

int main () {

    arvore_binaria *a = (arvore_binaria*)malloc(sizeof(arvore_binaria));
    cria_arv_vazia ();

    //inserir (a, 50);
    // inserir (a, 30);
    //inserir (a, 90);
    //inserir (a, 20);
    //inserir (a, 40);
    //inserir (a, 95);
    //inserir (a, 10);
    //inserir (a, 35);
    //inserir (a, 45);

    printf("\nBuscando o 95 : %d (1 - Contém / 0 - não contém)\n", buscar(a, 95));

    printf("\nBuscando o menor valor : %d \n", min(a));

    printf("\n");
    pre_ordem(a);
    printf("\n");
    pos_ordem(a);
    printf("\n");
    in_ordem(a);
    printf("\n");
printf("%d",maior_ramo(a));

return 0;


}
