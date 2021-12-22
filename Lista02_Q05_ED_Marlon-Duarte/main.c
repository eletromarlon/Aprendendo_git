#include <stdio.h>
#include <stdlib.h>
#include "calculaCubo.h"

int main()
{
    float valor, resultado;
    printf("\nDigite o lado do cubo: ");
    scanf("%f", &valor);
    medida(valor);
    resultado = area(valor);
    printf("\nA area do cubo é: %f ", resultado);
    resultado = volume(valor);
    printf("\nO volume do cubo é: %f", resultado);

    return 0;
}
