#include<stdio.h>
#include<stdlib.h>

#define V 10

void minMaxMedio (int vetor[], int tam, int* min, int* max, double* medio){
    float media=0.0;
    *max = vetor[0];
    *min = vetor[0];

    for (int i=0;i<V;i++){
        media += vetor[i];
        if (vetor[i]>=*max){
            *max = vetor[i];
        }
        if (vetor[i]<=*min){
            *min = vetor[i];
        }
    }
    *medio = (media/V);

}

void main (){
    int vetor[V], min, max;
    double medio;

    for (int i=0;i<V;i++){
        printf("Digite um valor para Vet %d \n", i);
        scanf("%d", &vetor[i]);
    }

    minMaxMedio(vetor, V, &min, &max, &medio);

    printf("O valor máximo  é  %d \n", max);
    printf("O valor mínimo  é  %d \n", min);
    printf("O valor da média é %lf \n", medio);
}
