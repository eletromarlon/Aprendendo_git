#include <stdio.h>
#include <stdlib.h>
#include "l_e_o.h"
#define tamanho 10
int main()
{
    int temp;
    printf("Programa iniciado!\n");
    create(tamanho);

    printf("\nVamos alocar: [16, 21, 1, 5, 7, 34, -12] respectivamente!\n");

    add(16, tamanho);
    add(21, tamanho);
    add(1, tamanho);
    add(5, tamanho);
    add(7, tamanho);
    add(34, tamanho);
    add(-12, tamanho);
    print_all();
    printf("\n\nRemovendo o 5. Status %d\n", remove_item(5));

    printf("\n\nBusca Linear pela chave 7 ");

        temp = linearSearch(7);
            if (temp < 0)
                printf("\n" );
            else
                printf("\n\nChave no indice %d", temp);

    printf("\n\nBusca Binaria pela chave 21 ");

        temp = bynarySearch(21);
            if (temp < 0)
                printf("\n" );
            else
                printf("\n\nChave no indice %d", temp);

    printf("\nNúmero de itens: %d\n", size_lista());

    print_all();

    clear_vetor();
    return 0;
}
