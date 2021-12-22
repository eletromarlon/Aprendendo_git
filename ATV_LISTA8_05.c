#include <stdio.h>
#include <stdlib.h>

void calcula_hexagono(float lado, float *a, float *b){
    *b = lado*6;
    *a = (3*(lado*lado)*(1.732050808))/2;
}

void main (){
    float lado, area, perimetro;
    do {
    printf("Digite o lado do hexagono: \n ");
    scanf("%f", &lado);
    } while (lado<=0);

    calcula_hexagono(lado, &area, &perimetro);

    printf("Area = %.2f\n", area);
    printf("Perimetro = %.2f\n", perimetro);
}

