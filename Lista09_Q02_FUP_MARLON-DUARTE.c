#include<stdio.h>
#include<stdlib.h>

#define V 10

int ePar(int n){
    if (n % 2 == 0)
        return 1;
    else
        return 0;
}


void main(){
    int vet[V]={}, i=0;

    for (i;i<10;i++){
        vet[i]= i+(2*i);
        if (ePar(vet[i]) == 1)
            printf("%d Par\n", vet[i]);
        else
            printf("%d \n", vet[i]);
    }
}

