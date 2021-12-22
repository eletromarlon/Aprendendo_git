#include "itens_AVL.h"

int altura_AVL(Tnode *a){
    int alt_esq=0, alt_dir=0;
    if (a == NULL)
        return 0;
    else{
        alt_esq = altura_AVL(a->esq);
        alt_dir = altura_AVL(a->dir);
        if (alt_esq > alt_dir)
            return (1 + alt_esq);
        else
            return (1 + alt_dir);
    }
}

int calcula_FB(Tnode *a){
    return (altura_AVL(a->esq) - altura_AVL(a->dir));
}

Tnode* rot_simples_esquerda(Tnode* a){
  Tnode *aux;
  aux = a->dir;
  a->dir = aux->esq;
  aux->esq = a;
  a = aux;
  return a;
}
Tnode * rot_simples_direita(Tnode *a){
  Tnode *aux;

  aux = a->esq;
  a->esq = aux->dir;
  aux->dir = a;
  a = aux;
  return a;
}
Tnode * balanceio_esquerda(Tnode *a){
  int fator = calcula_FB(a->esq );
  if (fator > 0){
    return rot_simples_direita(a);
  }
  else if (fator < 0)// Rotação Dupla Direita
  {
    a->esq = rot_simples_esquerda(a->esq);
    a = rot_simples_direita(a);
	return a;
  }
  else
  	return a;
}

Tnode * balanceio_direita(Tnode *a){
    int fator = calcula_FB(a->dir);
    if ( fator< 0 ){
        return rot_simples_esquerda(a);
    }else if (fator > 0 ){
        a->dir = rot_simples_direita(a->dir);
        a = rot_simples_esquerda(a);
        return a;
    }else
        return a;
}

Tnode* balanceamento(Tnode* a){
	int fator = calcula_FB(a);
	if ( fator > 1)
		return balanceio_esquerda(a);
	else if (fator < -1 )
		return balanceio_direita(a);
	return a;
}
Tnode* inserir_avl(Tnode* a, int elemento){
    if (a == NULL){
        a = (Tnode *)malloc(sizeof(Tnode));
        a->elemento = elemento;
        a->esq = NULL;
        a->dir = NULL;
        return a;
    }else{
        if ( a->elemento > elemento )  {
            a->esq = inserir_avl(a->esq,elemento);
            a = balanceamento(a);
        }else{
            a->dir = inserir_avl(a->dir,elemento);
            a = balanceamento(a);
        }
    }
    return 0;
}

void imprime_avl(Tnode* a){
    if (a == NULL){
		return;
	}
    printf("%d",a->elemento);

    if(a->esq != NULL)
        printf("(E:%d)",a->esq->elemento);
    if(a->dir != NULL)
        printf("(D:%d)",a->dir->elemento);
    printf("\n");

    imprime_avl(a->esq);
    imprime_avl(a->dir);
}
