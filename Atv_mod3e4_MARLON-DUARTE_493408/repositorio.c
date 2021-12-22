#include <stdio.h>
#include <stdlib.h>
#include "repositorio.h"


Item *ptr_item;
int k=0;

///Função de criação de repositório para inserçaõ de itens!

void create_repositorio (){
    ptr_item = (Item*) realloc(ptr_item, sizeof(Item));
}

///Função de retorno de status de repositorio, retorna o tamanho do mesmo!

int tamanho(){
    return k++;
}

///Função que organiza os dados dentro do vetor!


void organizador(){
    ptr_item = (Item*) realloc(ptr_item, (k+1)*sizeof(Item));

    Item temp;

    for (int i=0;i<=k;i++){
        for (int j=i;j<=k;j++){
            if (ptr_item[i].codigo > ptr_item[j].codigo){
                temp = ptr_item[i];
                ptr_item[i] = ptr_item[j];
                ptr_item[j] = temp;
            }
        }
    }
}

///Função responśvel por adicionar valores no vetor!

//void guardar_no_repositorio(int codigo, char * valor){
//    ptr_item = (Item*) realloc(ptr_item, (k+1)*sizeof(Item));

 //   ptr_item[k].codigo = codigo;
//    ptr_item[k].valor = valor;

        organizador();

    //printf("\nItem inserido!\n");
    tamanho();
}

///Função de busca de valores dentro do vetor e retorna a posição!

int find_valor(char * valor){

    for (int i=0; i<=k;i++){
        if (valor == ptr_item[i].valor){
            return ptr_item[i].codigo;
        }
    }
    return -1;
}

///Função de busca de códigos dentro do vetor e que retorna a posição!

char * find_codigo(int cod){
    int esq = 0, dir=k;

    while (esq <= dir){
        int meio = (esq+dir) / 2;

        if (ptr_item[meio].codigo == cod){
            return ptr_item[meio].valor;
        } else if (ptr_item[meio].codigo > cod){
            dir = meio -1;
        } else {
            esq = meio + 1;
        }
    }
    return "ERROR";
}
///Função responsável por retirar o maior valor do repositório!

float tratar(){
    Item temp = ptr_item[k-1];
    k--;
    return -1.5;
}

///Função responsável por imprimir os dados do vetor

int imprime_repositorio(){
    if (k>0){
        for (int i=0;i<k;i++){
            printf("\nComunidade '' %s '' - ID %i \n", ptr_item[i].valor, ptr_item[i].codigo);
        }
        return 1;
    } else
        return -1;
}


///Função de verificação do status do vetor!

int esta_cheio(){
    if (k==0)
        return 0;
    else
        return 1;
}

///Função de verificação do status do vetor!

int esta_vazio(){
    if (esta_cheio())
        return 0;
    else
        return 1;
}

///Função responsável por "zerar" o vetor!

void limpar_repositorio(){
    k=0;
    free(ptr_item);
}
