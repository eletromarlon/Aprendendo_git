#include "tree_bin.h"
int cont = 1;

No *criarRaiz(ArvoreBinaria *arvore, char valor) {
	 arvore->raiz = (No *) malloc(sizeof (No));
	 if (arvore->raiz != NULL) {
		 arvore->raiz->filhoEsquerda = NULL;
		 arvore->raiz->filhoDireita = NULL;
		 arvore->raiz->valor = valor;
	 }
	 return arvore->raiz;
}

ArvoreBinaria *criar() {
	 ArvoreBinaria *arv = (ArvoreBinaria *)malloc(sizeof(ArvoreBinaria));
	 if (arv != NULL) {
		arv->raiz = NULL;
	 }
	 return arv;
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
    cont++;
    return v_f;
}

int size_tree(){
    return cont;
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
    if (arvore->raiz == NULL)
        return -1;
    else
        return (prof_d(arvore->raiz, valor, 0));

}

void clear(ArvoreBinaria *arvore){
    free(arvore);
}
