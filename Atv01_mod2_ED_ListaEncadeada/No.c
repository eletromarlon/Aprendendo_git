 #include <stdio.h>
 #include <stdlib.h>
 #include "No.h"

 No* createNo(int v, No* proximo){

 	No * n = (No*) malloc(sizeof(No));

 	n->valor = v;
 	n->proximo = proximo;

 	return n;

 }

 void printNo(No* n){

 	if(n != NULL && n->proximo != NULL)
 		printf("No [valor: %i, proximo: %i]\n", n->valor, n->proximo->valor);
 	else if(n != NULL)
 		printf("No [valor: %i, proximo: NULL]\n", n->valor);
 	else
 		printf("NULL\n");

 }

 void freeNo(No* n){
 	free(n);
 }
