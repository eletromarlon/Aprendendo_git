#include <stdio.h>
#include <stdlib.h>
#define LADO_ESQ 0
#define LADO_DIR 1
#define false 0
#define true 1
int count = 1;


typedef struct no{
	char valor;
	struct no *filhoEsquerda;
	struct no *filhoDireita;
 } No;


typedef struct {
	No *raiz;
} ArvoreBinaria;

ArvoreBinaria *criar() {
	 ArvoreBinaria *arv = (ArvoreBinaria *)malloc(sizeof(ArvoreBinaria));
	 if (arv != NULL) {
		arv->raiz = NULL;
	 }
	 return arv;
}

//criar raiz (root)
No *criarRaiz(ArvoreBinaria *arvore, char valor) {
	 arvore->raiz = (No *) malloc(sizeof (No));
	 if (arvore->raiz != NULL) {
		 arvore->raiz->filhoEsquerda = NULL;
		 arvore->raiz->filhoDireita = NULL;
		 arvore->raiz->valor = valor;
	 }
	 return arvore->raiz;
}

No *add(int lado, No *v, char w){
	No *v_f = (No*) malloc(sizeof(No));

	if (v_f != NULL) {
		v_f->filhoDireita = NULL;
		v_f->filhoEsquerda = NULL;
		v_f->valor = w;

        if (lado == LADO_ESQ){
            v->filhoEsquerda = v_f;
        } else {
            v->filhoDireita = v_f;
        }
    }
    count++;
    return v_f;
}

int is_empty(ArvoreBinaria *arvore){
    if (arvore->raiz == NULL)
        return true;
    else
        return false;
}

void pre_ordem_aux(No *raiz){
    if ( raiz != NULL){
        printf("%c - ", raiz->valor);
        pre_ordem_aux(raiz->filhoEsquerda);
        pre_ordem_aux(raiz->filhoDireita);
    }
}

void pre_ordem (ArvoreBinaria *arvore){
    pre_ordem_aux(arvore->raiz);
}

void em_ordem_aux(No *raiz){
    if (raiz != NULL){
        em_ordem_aux(raiz->filhoEsquerda);
        printf("%c - ", raiz->valor);
        em_ordem_aux(raiz->filhoDireita);
    }
}

void em_ordem(ArvoreBinaria *arvore){
    em_ordem_aux(arvore->raiz);
}

void pos_ordem_aux(No *raiz){
    if(raiz != NULL){
        pos_ordem_aux(raiz->filhoEsquerda);
        pos_ordem_aux(raiz->filhoDireita);
        printf("%c - ", raiz->valor);
    }
}

void pos_ordem(ArvoreBinaria *arvore){
    pos_ordem_aux(arvore->raiz);
}

int prof_d(No *raiz, int valor, int comparador){
    int saida = 0;

    do {

        if (NULL == raiz)
            break;

        if (raiz->valor == valor) {
            saida = comparador;
            break;
        }

        saida = prof_d(raiz->filhoEsquerda, valor, comparador+1);

        if (saida)
            break;

        saida = prof_d(raiz->filhoDireita, valor, comparador+1);

        if(saida)
            break;

    }while(0);

   return saida;
}

int find_tree(ArvoreBinaria *arvore, char valor){
    int saida = 0;
    if (arvore->raiz == NULL)
        return -1;
    else
        return (prof_d(arvore->raiz, valor, 0));

}

void clear(ArvoreBinaria *arvore){
    free(arvore);
}

int main (){
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

  	printf("%i", count);

    printf("\n");

    printf("%d", is_empty(av));

	return 0;
}
