#include <stdio.h>
#include <stdlib.h>

void inserir(int *vetor, int tam, int x){


    printf("Valor em x=%i\n", x);
    printf("\n\n");

    vetor = (int *)realloc (vetor, (tam+1)*sizeof(int));

        if (!vetor) {
            printf ("\nERRO!!\n");
            exit (1);
        }

    vetor[tam]=x;

}

int main(){
    int *vetor, y=5;

    vetor = malloc (y*sizeof(int));

    if (!vetor){
        printf (" Erro de memória!! ");
        exit (1);
        }

    for (int i=0;i<y;i++){
        vetor[i] = y*(i+1);
    }

    for(int i=0;i<(y);i++){
        printf("Valor anterior no indice %i = %i\n", i, vetor[i]);
    }
    printf("\n\n");

    inserir(vetor, y, 10);

    for(int i=0;i<(y+1);i++){
        printf("Valor posterior no indice %i = %i\n", i, vetor[i]);
    }
}
