#include <stdio.h>
#include <stdlib.h>

int soma_impares(int n){
    int i = 1, contador = 0;
        for (i; i<=n; i++){
            if ((i > 1) && (i % 2 != 0)){
                contador = contador + i;
            }
        }
    contador = contador + 1;
    return contador;
}

void main (){
    int numero, resultado;
    printf("Digite o máximo valor para contagem dos ímpares: \n ");
    scanf("%d", &numero);

    resultado = soma_impares(numero);

    printf("O resultado da soma é %d \n", resultado);
}

