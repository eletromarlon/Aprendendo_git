#include <stdio.h>
#include <stdlib.h>
#include "ListaCircular.h"

ListaDuplamenteEncadeada *create() {
	 ListaDuplamenteEncadeada *lista = (ListaDuplamenteEncadeada *)malloc(sizeof (ListaDuplamenteEncadeada));

	 if(lista != NULL) {
		 lista->inicio = NULL;
		 lista->fim = NULL;
		 lista->tamanho = 0;
	 }

	 return lista;
}

void printAll (ListaDuplamenteEncadeada* l){
    No* p = l->inicio;
    /* faz p apontar para o nó inicial */
    /* testa se lista não é vazia */
    if (p != NULL)  {
    /* percorre os elementos até alcançar novamente o início */
        do {
            printf("%d\n", p->valor);     /* imprime informação do nó */
            p = p->proximo; /* avança para o próximo nó */
        } while (p != l->inicio);
    }
}
