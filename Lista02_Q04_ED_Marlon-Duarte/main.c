#include <stdio.h>
#include <stdlib.h>
#include "CalculaCirculo.h"

int main(){
    float raio, resultado, pi=3.1415;

    printf("\nDigite o raio da circunferencia: ");
    scanf("%f", &raio);

        resultado = circumferencia (pi, raio);

    printf("\nO valor da circunferencia é: %f", resultado);

        resultado = area(pi, raio);

    printf("\nO valor da area é: %f", resultado);

    return 0;
}
