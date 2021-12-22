#include<stdio.h>
#include<stdlib.h>

HEAP_SIZE = 20;

struct Heap{
    int *vetor;
    int contador;
    int tamanho;
    int tipo_heap; //0 para heap min e 1 para heap max
};
typedef struct Heap Heap;

Heap *criar_heap(int tamanho,int tipo_heap);
void insert(Heap *h, int key);
void print(Heap *h);
void heap_acima(Heap *h,int index);
void heap_abaixo(Heap *h, int parent_node);
int PopMin(Heap *h);

int main(){
    int i;
    Heap *heap = criar_heap(HEAP_SIZE, 0); //Min Heap
    if( heap == NULL ){
        printf("__Memory Issue____\n");
        return -1;
    }

    for(i =9;i>0;i--)
        insert(heap, i);

    print(heap);

    for(i=9;i>=0;i--){
        printf(" Pop Minima : %d\n", PopMin(heap));
        //print(heap);
    }
    return 0;
}

Heap *criar_heap(int tamanho,int tipo_heap){
    Heap *h = (Heap * ) malloc(sizeof(Heap)); //one is number of heap

    //check if memory allocation is fails
    if(h == NULL){
        printf("Memory Error!");
        return;
    }
    h->tipo_heap = tipo_heap;
    h->contador=0;
    h->tamanho = tamanho;
    h->vetor = (int *) malloc(tamanho*sizeof(int)); //size in bytes

    //check if allocation succeed
    if ( h->vetor == NULL){
        printf("Memory Error!");
        return;
    }
    return h;
}

void insert(Heap *h, int key){
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

        // recursive  call
        heap_abaixo(h, min);
    }
}

int PopMin(Heap *h){
    int pop;
    if(h->contador==0){
        printf("\n__Heap is Empty__\n");
        return -1;
    }
    // replace first node by last and delete last
    pop = h->vetor[0];
    h->vetor[0] = h->vetor[h->contador-1];
    h->contador--;
    heap_abaixo(h, 0);
    return pop;
}
void print(Heap *h){
    int i;
    printf("____________Print Heap_____________\n");
    for(i=0;i< h->contador;i++){
        printf("-> %d ",h->vetor[i]);
    }
    printf("->__/\\__\n");
}
