#include <stdio.h>

main (){
    float a, a1, b, b1;
    printf("Digite o valor da Nota 1:");
    scanf("%f", &a);
    printf("Digite o peso da Nota 1:");
    scanf("%f", &a1);
    printf("Digite o valor da Nota 2:");
    scanf("%f", &b);
    printf("Digite o peso da Nota 2:");
    scanf("%f", &b1);
    printf("O valor da média ponderada das duas notas é: %.2f", (a*a1+b*b1)/(a1+b1));
}



