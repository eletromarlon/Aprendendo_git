#include "fila_pref.h"

Heap *criar_heap(int tamanho,int tipo_heap){
    Heap *h = (Heap * ) malloc(sizeof(Heap));

    if(h == NULL){
        printf("Memory Error!");
        return;
    }
    h->tipo_heap = tipo_heap;
    h->contador=0;
    h->tamanho = tamanho;
    h->vetor = (int *) malloc(tamanho*sizeof(int));

    /**Verifica se a alocação funcionuo corretamente */
    if ( h->vetor == NULL){
        printf("Memory Error!");
        return;
    }
    return h;
}

void insert(Heap *h, int key){
    printf("\n\n\t\tA senha %d está na fila", key);
    if( h->contador < h->tamanho){
        h->vetor[h->contador] = key;
        heap_acima(h, h->contador);
        h->contador++;
    }
}

void heap_acima(Heap *h,int index){
    int temp;
    int parent_node = (index-1)/2;

    if(h->vetor[parent_node] > h->vetor[index]){
        temp = h->vetor[parent_node];
        h->vetor[parent_node] = h->vetor[index];
        h->vetor[index] = temp;
        heap_acima(h,parent_node);
    }
}

void heap_abaixo(Heap *h, int parent_node){
    int left = parent_node*2+1;
    int right = parent_node*2+2;
    int min;
    int temp;

    if(left >= h->contador || left <0)
        left = -1;
    if(right >= h->contador || right <0)
        right = -1;

    if(left != -1 && h->vetor[left] < h->vetor[parent_node])
        min=left;
    else
        min =parent_node;
    if(right != -1 && h->vetor[right] < h->vetor[min])
        min = right;

    if(min != parent_node){
        temp = h->vetor[min];
        h->vetor[min] = h->vetor[parent_node];
        h->vetor[parent_node] = temp;

        /**Chamada com recursividade*/
        heap_abaixo(h, min);
    }
}

int PopMin(Heap *h){
    int pop;
    if(h->contador==0){
        return -1;
    }
    /** Substitui o primeiro no pelo ultimo e exclui o ultimo*/
    pop = h->vetor[0];
    h->vetor[0] = h->vetor[h->contador-1];
    h->contador--;
    heap_abaixo(h, 0);
    printf("\n\n\tSaiu da fila %d", pop);
    return pop;
}

int status_fila(Heap *h){
    for(int i=0;i < h->contador;i++){
        if ((h->vetor[i]) > 0){
            return 1;
        }
    }
    return 0;
}
