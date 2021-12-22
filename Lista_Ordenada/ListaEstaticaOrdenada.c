#include <stdio.h>
#include <stdlib.h>
#include "ListaEstaticaOrdenada.h"

ListaEstaticaOrdenada* create(int n){

	ListaEstaticaOrdenada * p = (ListaEstaticaOrdenada*) malloc(sizeof(ListaEstaticaOrdenada));

 	p->n = n;
 	p->k = 0;

 	p->dados = (int*) calloc(sizeof(int) , n);

 	return p;

}


int add(ListaEstaticaOrdenada* ed, int e){

	if(ed!=NULL && ed->k < ed->n ) {

			int i = 0, posicao = ed->k;


			for(i = 0; i < ed->k; i++){

				if(e < ed->dados[i]){ //VERIFICA AONDE O ELEMENTO DEVE SER INSERIDO
					posicao = i;
					break;
				}

			}

			if(posicao != ed->k){ //SE O ELEMENTO NÃO SERÁ INSERIDO NO FINAL DO VETOR, ENTÃO REMANEJA OS ELEMENTOS PELO VETOR

				for(i = ed->k+1; i > posicao; i--){

					swap(ed->dados, i-1, i);

				}

			}

			ed->dados[posicao] = e;
			ed->k++;

			return 1;

	}
	else{

		return 0;

	}

}

void swap(int* v, int i, int j){
	int aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

void printAll(ListaEstaticaOrdenada* ed){

	int i = 0;

	printf("\nLista ");

	if(ed->k > 0){

		printf("[");

		for(i = 0 ; i < ed->n; i++){
			printf(" %i ", ed->dados[i]);
		}

		printf("]\n");

	}
	else
		printf("[ ]\n");
}



