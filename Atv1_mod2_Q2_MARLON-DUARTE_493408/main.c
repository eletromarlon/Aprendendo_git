#include <stdio.h>
#include <stdlib.h>
#include "lcde.h"

int main(){

    lista_cde * lista = create();

    add_item(lista, 10);
    add_item(lista, 8);
    add_item(lista, 5);
    add_item(lista, 15);
    add_item(lista, 12);
    add_item(lista, 26);

    getchar();

    printf("\nVamos remover o 8!\n");
    remove_item(lista, 8);
    printf("\nO tamanho da lista está %d\n", size_item(lista));

    printf("\n\nProcurando a posição do 12!\n");
    find_item(lista, 12);
    printAll(lista);
    clear_item(lista);
    printAll(lista);

    return 0;
}
