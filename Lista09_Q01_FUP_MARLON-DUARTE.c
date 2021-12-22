#include<stdio.h>
#include<stdlib.h>

#define V 10

void zeraVetor(int vet[], int tam){
    for (int i=0;i<10;i++){
        vet[i]=0;
    }
}

void main(){
    int vet[V]={}, i=0;

    for (i;i<10;i++){
        vet[i]= i+2;
        printf("Valor no vetor %d é %d \n", i, vet[i]);
    }
    zeraVetor(vet, V);
    i=0;
    for (i;i<10;i++){
        printf("O indice %d do vetor contém %d \n", i, vet[i]);
    }
}
