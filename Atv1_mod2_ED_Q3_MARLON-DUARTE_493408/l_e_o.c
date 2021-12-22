#include <stdio.h>
#include <stdlib.h>
#include "l_e_o.h"

void create(int n){
    vetor = (int*) realloc (vetor, n*(sizeof(int)));
    tam = -1;
    if (vetor == NULL) {
        printf ("\nERRO!\n");
        exit (1);
    } else
        printf("\n\nEspaço alocado com sucesso!\n");

}

void cria_vaga(int indice){         //Função local, complementa a função do TAD "add".

    for (int i=tam;i>indice;i--){
        if (i>0){
            vetor[i]=vetor[(i-1)];
        }
    }
}

int add(int valor, int espaco){
    posicao = 0;

    if (isFull(espaco) == TRUE){
        printf("\n\nVetor cheio!!!\n");
        return FALSE;
    }

    if (isempty() == TRUE){
        tam++;
        vetor[tam] = valor;
        return TRUE;
    }
    tam++;
    while (posicao < tam){
        if (vetor[posicao] < valor){
            posicao++;

        }else {
            cria_vaga(posicao);
            vetor[posicao]=valor;
            return TRUE;
        }
    }
    vetor[posicao] = valor;

    return TRUE;
}

void reorganiza(int indice){         //Função local que complementa a função do TAD "remove_item".

    for (int i=indice;i<tam;i++){
        vetor[i]=vetor[(i+1)];
    }
    tam--;
}

int remove_item(int chave){
    posicao = 0;
    if (isempty() == TRUE){
        printf("\n\nVazio! Nada a remover!\n");
        return FALSE;
    }
    while (posicao < tam+1){
        if (vetor[posicao] == chave){
            reorganiza(posicao);
            return TRUE;
            }
        posicao++;
    }
    return FALSE;
}

int size_lista(){
    return tam+1;
}

int linearSearch(int chave){
    for (int i=0;i<tam+1;i++){
        if (vetor[i] == chave)
            return i;
    }
    printf("\n\nChave não encontrada!\n");
    return -404;
}

int bynarySearch(int chave){
    int esq = 0, dir = tam;

    while (esq <= dir){
        int meio = (esq + dir)/2;

        if (vetor[meio] == chave)
            return meio;
         else if (vetor[meio] > chave)
            dir = meio -1;
         else
            esq = meio + 1;
    }
    printf("\n\nChave não encontrada!\n");
    return -404;
}


int isempty(){
    if (tam < 0)
        return TRUE;
    else
        return FALSE;
}

int isFull(int espaco){
    if ((tam+1) == espaco)
        return TRUE;
    else
        return FALSE;
}

int clear_vetor(){
    free(vetor);
    return TRUE;
}

void print_all(){
    printf("\n");
    printf("[");
    for (int i=0;i<tam+1;i++){
        printf(" %d ,", vetor[i]);
    }
    printf("]");

}
