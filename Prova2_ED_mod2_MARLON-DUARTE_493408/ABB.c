#include "ABB.h"
int cont=0;

/**Cria uma arvore_binaria vazia!
Apresenta complexidade O(1), ou seja, complexidade constante
pois depende apenas de inserir um status em um ponteiro e
deixa-lo pronto para receber valores por -add.
*/
arvore_binaria* create() {
   return NULL;
}

/**Destroi uma arvore_binaria!
Apresenta complexidade linear, O(n), pois o número de "recursos" feitos
está relacionado ao número de itens inseridos dentro da raiz e das sub
raízes da árvore, ou seja, depende do tamanho da árvore.
*/
void clear (arvore_binaria *arv) {
   if (arv != NULL) {
      clear(arv->esq);
      clear(arv->dir);
      free(arv);
   }
}

/**Cria um no em uma arvore_binaria!
Apresenta complexidade linear, O(n), pois o número de "recursos" realizados
durante as operações, estão relacionados ao número de itens já inseridos dentro
da raíz da árvore e de suas sub raízes.
*/
arvore_binaria* add (arvore_binaria *a, int v){
    if(a == NULL){
        a=(arvore_binaria*)malloc(sizeof(arvore_binaria));
        a->valor = v;
        a->esq = NULL;
        a->dir = NULL;
    }
    else if(v < a->valor){
        a->esq = add(a->esq,v);
    }
    else{
        a->dir = add(a->dir,v);
    }
    return a;
}

/**Recebe uma árvore e imprime todos os seus elementos em pre-ordem!
Apresenta complexidade de razão O(n), seguindo a mesma lógica de add e clear,
pois o número de "recursos" realizados durante as operações, está relacionado
ao número de itens já inseridos dentro da raíz da árvore e de suas sub raízes.
Portanto, tem relação com o tamanho da árvore.
*/
void pre_ordem (arvore_binaria *arv) {
    if (arv != NULL){
       printf ("%d, ", arv->valor);
       pre_ordem (arv->esq);
       pre_ordem (arv->dir);

    }
}

/**Recebe uma árvore e imprime todos os seus elementos em "em ordem"!
Apresenta complexidade de razão O(n), seguindo a mesma lógica de add e clear,
pois o número de "recursos" realizados durante as operações, está relacionado
ao número de itens já inseridos dentro da raíz da árvore e de suas sub raízes.
Portanto, tem relação com o tamanho da árvore.
*/
void in_ordem (arvore_binaria *arv) {
   if (arv != NULL) {
      in_ordem (arv->esq);
      printf ("%d, ", arv->valor);
      in_ordem (arv->dir);
   }
}

/**Recebe uma árvore e imprime todos os seus elementos em pós-ordem!
Apresenta complexidade de razão O(n), seguindo a mesma lógica de add e clear,
pois o número de "recursos" realizados durante as operações, está relacionado
ao número de itens já inseridos dentro da raíz da árvore e de suas sub raízes.
Portanto, tem relação com o tamanho da árvore.
*/
void pos_ordem (arvore_binaria *arv){
    if (arv != NULL){
        pos_ordem (arv->esq);
        pos_ordem (arv->dir);
        printf("%d, ", arv->valor);
    }
}

/**Realiza a busca por um determinado valor na árvore e retorna a profundidade!
Apresenta complexidade O(n), no pior caso, pois à medida que o valor está mais
próximo às folhas o tempo de busca será maior. Portanto, há de depender do tama-
nho da árvore.
*/
int find(arvore_binaria *a, int v){
    if(a==NULL){
        return -1;
    }
    else if(v < a->valor){
        cont++;
        return find(a->esq,v);
    }
    else if(v > a->valor){
        cont++;
        return find(a->dir,v);
    }
    else{
        return cont-1;
    }
}

/**Retira um valor determinado de dentro da árvore e exclui o mesmo da estrutura!
Apresenta complexidade linear, O(n), no pior caso, pois, assim como outras funções
deste código, depende fundamentalmente do tamanho da árvore. Em outros casos,
dependerá da profundidade do item buscado. Portanto, à medida que a árvore cresce,
torna-se mais demorada o encontro do valor para exclusão.
*/
arvore_binaria* retirar (arvore_binaria *a, int v){
    if(a == NULL){
        return NULL;
    }
    else{
        if(a->valor >v){
            a->esq = retirar(a->esq,v);
        }
        else if (a->valor <v){
            a->dir = retirar (a->dir,v);
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
                a->valor = tmp->valor;
                tmp->valor = v;
                a->esq = retirar(a->esq,v);
            }
        }
    }
    return a;
}
