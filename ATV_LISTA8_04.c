#include <stdio.h>
#include <stdlib.h>

void calcula_hexagono(float lado, float *a, float *b){
    *b = lado*6;
    *a = (3*(lado*lado)*(1.732050808))/2;
}

void main (){
    float lado, area, perimetro;
    printf("Digite o lado do hexagono (lado > 0): ");
    scanf(" %f", &lado);

    calcula_hexagono(lado, &area, &perimetro);

    printf("Area = %.2f\n", area);
    printf("Perimetro = %.2f\n", perimetro);
}

