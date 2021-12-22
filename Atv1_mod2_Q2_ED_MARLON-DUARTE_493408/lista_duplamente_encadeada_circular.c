#include <stdio.h>
#include <stdlib.h>
#include "lista_duplamente_encadeada_circular.h"

lista_d_e_c *create(){
	 lista_d_e_c *lista = (lista_d_e_c *)malloc(sizeof (lista_d_e_c));

	 if(lista != NULL) {
		 lista->inicio = NULL;
		 lista->fim = NULL;
		 lista->tamanho = 0;
	 }

	 return lista;
}

