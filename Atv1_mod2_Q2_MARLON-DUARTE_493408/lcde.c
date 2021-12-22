#include <stdio.h>
#include <stdlib.h>
#include "lcde.h"

lista_cde *create (){

    lista_cde *lista = (lista_cde *)malloc(sizeof (lista_cde));

	if(lista != NULL) {
        lista->inicio = NULL;
        lista->fim = NULL;
        lista->tamanho = 0;
    }

	 return lista;
}

int add_item(lista_cde *lista, int valor){

    no *pnovo = (no*) malloc(sizeof(no));

	if(pnovo != NULL) {
        pnovo->valor = valor;
        pnovo->proximo = NULL;

        if(lista->inicio == NULL) {
            lista->inicio = pnovo;
        }else {
            lista->fim->proximo = pnovo;
        }

        lista->fim = pnovo;
        lista->tamanho++;
        printf("\n\nValor add %d", pnovo->valor);
        return TRUE;
    }
    return FALSE;
}

int remove_item(lista_cde *lista, int chave){

    if (!isempty(lista)) {

        no *alvo = lista->inicio;
        no *anterior;

        while(alvo != NULL && alvo->valor != chave) {
            anterior = alvo;
            alvo = alvo->proximo;
        }

        if(alvo != NULL) {
            if(alvo != lista->inicio) {
                anterior->proximo = alvo->proximo;
            } else {
                lista->inicio = alvo->proximo;
            }

            if(alvo == lista->fim) {
                lista->fim = anterior;
            }

        lista->tamanho--;
        free(alvo);

        return TRUE;
        }
    }
    return FALSE;
}

int size_item(lista_cde *lista){
    return lista->tamanho;
}

int find_item(lista_cde *lista, int valor){
    int counter=0;

    if(isempty(lista))
        printf("Lista esta' vazia.\n");
    else{

        no *alvo = lista->inicio;

        while(alvo != NULL){
                                //printf("\n\n %d %d \n\n", alvo->valor, alvo->proximo->valor);
            if (valor == alvo->valor){
                printf("\n\nEncontrado no indice %d \n\n", counter);
            return counter;
            }

        alvo = alvo->proximo;
        counter++;
        }
    }

    return -1;
}

int isempty(lista_cde *lista){
    return lista->tamanho <= 0;
}

int clear_item(lista_cde *lista){

    free(lista);
    lista->tamanho = 0;

    return TRUE;
}

int printAll (lista_cde *l) {
    no *p = l->inicio;
                        // faz p apontar para o nó inicial
                        // testa se lista não é vazia
    if ((p != NULL) && (l->tamanho != 0)) {
                        // percorre os elementos até alcançar novamente o início
        for (int i=0;i<(l->tamanho);i++){
            printf(" %d -", p->valor);        // imprime informação do nó
            p = p->proximo;
        }
        printf("\n");
        return TRUE;
    }
    printf("\n\nLista Vazia!\n\n");
    return FALSE;

}

