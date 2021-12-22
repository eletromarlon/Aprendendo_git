#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef struct Nodo{
    int raiz;
    struct Nodo *filho_esquerdo;
    struct Nodo *filho_direito;
} No;

typedef No *arvore;

int is_empty (arvore a){
    return (a == NULL);}
    // Função para inserir um Novo elemento 'b' na arvoreore 'a'
arvore insere (arvore a, int b){
    arvore Nova;
    if (is_empty(a)){
        Nova = (arvore) malloc (sizeof(No));
        Nova->filho_esquerdo = NULL;
        Nova->filho_direito = NULL;
        Nova->raiz = b;

        printf("Insercao do numero %d na AB realizada!", b);

    return Nova;
    }else {
        if ( b > a->raiz )
            a->filho_direito = insere(a->filho_direito, b);
        else
            a->filho_esquerdo = insere(a->filho_esquerdo, b); /* Repeticoes sao inseridas na filho_esquerdouerda! */
        return a;
    }
}

void pre_ordem_aux(arvore r){
    if ( r != NULL){
        printf("%c - ", r->raiz);
        pre_ordem_aux(r->filho_esquerdo);
        pre_ordem_aux(r->filho_direito);
    }
}


int find(arvore a , int b){

    if (is_empty(a))
        return -1;
    else if ( a->raiz == b )
        return 1;
    else if ( b > a->raiz )
        return find(a->filho_direito, b);
    else return find(a->filho_esquerdo, b);
}

int main(){

    arvore a=NULL;
    int opcao=1;
    int num;

    while (opcao != 0){
        system("clear");
        printf("\n\n----------------MENU PRINCIPAL----------------");
        printf("\n\n 1 - Inserir Novo Numero na AB");
        printf("\n 2 - Buscar");
        printf("\n 3 - Pre-ordem");
        printf("\n 0 - Encerrar");
        printf("\n\n Opcao Escolhida: ");
        scanf("%d",&opcao);

        switch(opcao){

        case 1: system("clear");
            printf("\nInserir Novo valor: ");
            scanf("%d",&num);
            a = insere(a,num);
            system("pause>>null");
        break;

        case 2: system("clear");
            printf("\nBuscar o valor: ");
            scanf("%d",&num);
            printf("%i", find(a, num));
            system("pause>>null");
            break;
        case 3: system("clear");
            pre_ordem_aux(a);
        }
    }


    return 0;
}
