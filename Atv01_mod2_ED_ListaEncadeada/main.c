#include <stdio.h>
#include <stdlib.h>
#include "ListaEncadeada.h"

int main(int argc, char *argv[]) {

    ListaEncadeada * lista = create();

	printListaEncadeada(lista);

	add(lista, 10);

	printListaEncadeada(lista);

	add(lista, 5);

	printListaEncadeada(lista);

	add(lista, 15);

	add(lista, 25);

	add(lista, 50);

	printListaEncadeada(lista);

	printf("\n\n Tamanho da lista %d\n\n", size_p(lista));

	printf("\n\nFinder buscando o 26 = saida %d \n\n", finder(lista, 26));

	clear_p(lista);

    printListaEncadeada(lista);

                /*remover(lista, 10);

                printListaEncadeada(lista);

                remover(lista, 25);

                printListaEncadeada(lista);

                remover(lista, 5);

                printListaEncadeada(lista);
                */
	return 0;
}
