#include "tree_bin.h"

/*Cria uma arvore_binaria vazia!*/
arvore_binaria* cria_arv_vazia () {
   return NULL;
}

/*Destroi uma arvore_binaria!*/
void destroi_arv (arvore_binaria *arv) {
   if (arv != NULL) {
      destroi_arv (arv->esq);
      destroi_arv (arv->dir);
      free(arv);
   }
}

/*Cria um no em uma arvore_binaria!*/
arvore_binaria* inserir (arvore_binaria *a, int v){
    if(a == NULL){
        a=(arvore_binaria*)malloc(sizeof(arvore_binaria));
        a->info = v;
        a->esq = NULL;
        a->dir = NULL;
    }
    else if(v < a->info){
        a->esq = inserir(a->esq,v);
    }
    else{
        a->dir = inserir(a->dir,v);
    }
    return a;
}



void pre_ordem (arvore_binaria *arv) {
    if (arv != NULL){
       printf ("%d, ", arv->info);
       pre_ordem (arv->esq);
       pre_ordem (arv->dir);

    }
}

void in_ordem (arvore_binaria *arv) {
   if (arv != NULL) {
      in_ordem (arv->esq);
      printf ("%d, ", arv->info);
      in_ordem (arv->dir);
   }
}

void pos_ordem (arvore_binaria *arv){
    if (arv != NULL){
        pos_ordem (arv->esq);
        pos_ordem (arv->dir);
        printf("%d, ", arv->info);
    }
}

int buscar (arvore_binaria *a, int v){
    if(a==NULL){
        return 0;
    }
    else if(v < a->info){
        return buscar(a->esq,v);
    }
    else if(v > a->info){
        return buscar(a->dir,v);
    }
    else{
        return 1;
    }
}

int min (arvore_binaria *a){
    if( a->esq != NULL){
        return min(a->esq);
    }
    else{
         return a->info;
    }
}

int max (arvore_binaria *a){
    if (a->dir != NULL){
        return max(a->dir);
    }
    else{
        return a->info;
    }
}

arvore_binaria* Remover (arvore_binaria *a, int v){
    if(a == NULL){
        return NULL;
    }
    else{
        if(a->info >v){
            a->esq = Remover (a->esq,v);
        }
        else if (a->info <v){
            a->dir = Remover (a->dir,v);
        }
        else{
            if((a->esq == NULL) && (a->dir == NULL)){
                free(a);
                a=NULL;
            }
            else if(a->dir == NULL){
                arvore_binaria *tmp = a;
                a = a -> esq;
                free (tmp);
            }
            else if(a->esq == NULL){
                arvore_binaria *tmp = a;
                a = a -> dir;
                free (tmp);
            }
            else{
                arvore_binaria *tmp = a->esq;
                while(tmp->dir != NULL){
                    tmp=tmp->dir;
                }
                a->info = tmp->info;
                tmp->info = v;
                a->esq = Remover(a->esq,v);
            }
        }
    }
    return a;
}


void imprime_decrescente (arvore_binaria *arv){
    if (arv != NULL){
        printf("%d, ", max(arv));
        imprime_decrescente(Remover(arv, max(arv)));

    }
}


int contarNos(arvore_binaria *a){
   if(a == NULL)
        return 0;
   else
        return 1 + contarNos(a->esq) + contarNos(a->dir);
}

int maior(int a, int b){
    if(a > b)
        return a;
    else
        return b;
}

int maior_ramo(arvore_binaria *a){
   if((a == NULL)){
        return 0;
   }
   else{
        return maior(maior_ramo(a->dir) +a-> info, maior_ramo(a->esq) + a->info);
   }
}
