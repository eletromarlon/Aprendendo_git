#include <stdio.h>
#include <stdlib.h>
#include "tree_bin.h"

int main(){
	ArvoreBinaria *av = criar();

	printf("%d", is_empty(av));

	printf("\n");

	criarRaiz(av, 'A');

	add(LADO_ESQ, av->raiz, 'B');

	add(LADO_ESQ, av->raiz->filhoEsquerda, 'D');

	add(LADO_DIR, av->raiz->filhoEsquerda->filhoEsquerda, 'G');

	add(LADO_DIR, av->raiz, 'C');

	add(LADO_ESQ, av->raiz->filhoDireita, 'E');

	add(LADO_DIR, av->raiz->filhoDireita, 'F');

	add(LADO_ESQ, av->raiz->filhoDireita->filhoEsquerda, 'H');

    add(LADO_DIR, av->raiz->filhoDireita->filhoEsquerda, 'I');

    printf("\nBuscando F - Nivel %i\n", find_tree(av, 'F'));

    pre_ordem(av);

    printf("\n");

	em_ordem(av);

	printf("\n");

    pos_ordem(av);

    printf("\n");

  	printf("Tamanho %i", size_tree());

    printf("\n");

    printf("%d", is_empty(av));

    clear(av);

    printf("\n");

    printf("%d", is_empty(av));

	return 0;
}

