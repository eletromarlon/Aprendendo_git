//
// Created by acer on 21/01/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include "pilha5.h"

void inicia(node *PILHA)
{
    PILHA->topo = NULL;
    tam=0;
}

int menu(void)
{
    int opt;

    printf("Escolha a opcao\n");
    printf("0. Sair\n");
    printf("1. Zerar PILHA\n");
    printf("2. Exibir PILHA\n");
    printf("3. PUSH\n");
    printf("4. POP\n");
    printf("Opcao: ");
    scanf("%d", &opt);

    return opt;
}

void opcao(node *PILHA, int op)
{
    node *tmp;
    switch(op){
        case 0:
            libera(PILHA);
            break;

        case 1:
            libera(PILHA);
            inicia(PILHA);
            break;

        case 2:
            exibe(PILHA);
            break;

        case 3:
            push(PILHA);
            break;

        case 4:
            tmp= pop(PILHA);
            if(tmp != NULL)
                printf("Retirado: %3d\n\n", tmp->num);

            break;

        default:
            printf("Comando invalido\n\n");
    }
}

int vazia(node *PILHA)
{
    if(PILHA->topo == NULL) //Se em topo estiver NULL a pilha está vazia
        return 1;
    else
        return 0;
}

node *aloca()
{
    node *novo=(node *) malloc(sizeof(node));   //Para alocar espaço suficiente repetimos o malloc nessa função
    if(!novo){
        printf("Sem memoria disponivel!\n");
        exit(1);
    }else{
        printf("Novo elemento: ");              //Imprimo a chamada ao novo elemento, salvo ele em num, cada item da pilha sera um
        scanf("%d", &novo->num);                //novo nó, como sugere a ideia de pilha dinamica. O ponteiro criado guarda a
        return novo;                            //informação de ultimo da pilha
    }
}


void exibe(node *PILHA)
{
    if(vazia(PILHA)){
        printf("PILHA vazia!\n\n");
        return ;
    }

    node *tmp;
    tmp = PILHA->topo;
    printf("PILHA:");
    while( tmp != NULL){
        printf("%5d", tmp->num);
        tmp = tmp->topo;
    }
    printf("\n        ");
    int count;
    for(count=0 ; count < tam ; count++)
        printf("  ^  ");
    printf("\nOrdem:");
    for(count=0 ; count < tam ; count++)
        printf("%5d", count+1);


    printf("\n\n");
}

void libera(node *PILHA)
{
    if(!vazia(PILHA)){          //Se o valor de "vazia" for NULL a negação a tornará um true para o if e segue o código
        node *topoNode, *atual; //criando dois ponteiros da struct

        atual = PILHA->topo;
        while(atual != NULL){
            topoNode = atual->topo;
            free(atual);
            atual = topoNode;
        }
    }
}

void push(node *PILHA)
{
    node *novo=aloca();
    novo->topo = NULL;

    if(vazia(PILHA))
        PILHA->topo=novo;
    else{
        node *tmp = PILHA->topo;

        while(tmp->topo != NULL)
            tmp = tmp->topo;

        tmp->topo = novo;
    }
    tam++;
}


node *pop(node *PILHA)
{
    if(PILHA->topo == NULL){
        printf("PILHA ja vazia\n\n");
        return NULL;
    }else{
        node *ultimo = PILHA->topo,
                *penultimo = PILHA;

        while(ultimo->topo != NULL){
            penultimo = ultimo;
            ultimo = ultimo->topo;
        }

        penultimo->topo = NULL;
        tam--;
        return ultimo;
    }
}

/*FUNÇÃO PARA INVERTER OS DADOS DA PILHA

void inverte(node *PILHA){

    if (vazia())

}
*/
