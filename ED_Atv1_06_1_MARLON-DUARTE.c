#include<stdio.h>
#include<stdlib.h>

//int *vet;

void preenche (int *vet, int elementos){
    for (int i=0;i<elementos;i++){
        printf("Valor para o elemento %i do vetor \n ", i+1);
        scanf("%i", &vet[i]);
    }
}

void main(){
    int n, *vet;

    printf("Informe o numero de elementos do vetor\n");
    scanf("%i", &n);

    vet = (int *) malloc (n * sizeof(int));

    preenche(vet, n);

    for (int i=0;i<n;i++){
        printf("O valor no elemento %i é %i\n", i, vet[i]);
    }


    free(vet);

}
