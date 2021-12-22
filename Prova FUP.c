#include <stdio.h>

int main (){
    float baseMaior, baseMenor, altura, area;
    printf("Digite as bases: ");
    scanf("%f%f", &baseMaior, &baseMenor);
    printf("Digite a altura: ");
    scanf("%f", &altura);

    area = baseMaior+baseMenor*altura/2;
    printf("Area do trapezio: %f", area);

    return 0;
}
