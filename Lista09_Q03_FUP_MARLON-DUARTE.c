#include<stdio.h>
#include<stdlib.h>

#define V 10

int ePar(int n){
    if (n % 2 == 0)
        return 1;
    else
        return 0;
}

int contaPares(int vet[], int tam){
    int count=0;
    for (int i=0;i<V;i++){
        if (ePar(vet[i]) == 1)
        count += 1;
        }
    return count;

}

void main(){
    int vet[V]={}, i=0;

    for (i;i<10;i++){
        vet[i]= i+(5*i);
        printf("Ver %d tem %d \n", i, vet[i]);
    }

    printf("O total de números pares em vet é %d", contaPares(vet, V));

}
