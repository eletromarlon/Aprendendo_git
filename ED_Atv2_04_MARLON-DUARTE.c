#include<stdio.h>
#include<stdlib.h>
#include "CalculaCirculo.h"
#define pi 3.1415

int main () {
    float *saida, raio;

    printf("Informe o raio do circulo: \n");
    scanf ("%f", &raio);

    cumprimento (pi, raio, saida);

    printf("O resultado da circunferencia é : %f", *saida);
    return 0;
}
