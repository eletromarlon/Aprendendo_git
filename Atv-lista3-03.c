#include <stdio.h>

int main (){
    int num1, num2, den1, den2, calcnum, calcden;
    printf("Digite o primeiro numerador:\n");
    scanf("%d", &num1);
    printf("Digite o primeiro denominador:\n");
    scanf("%d", &den1);
    printf("Digite o segundo numerador:\n");
    scanf("%d", &num2);
    printf("Digite o segundo denominador:\n");
    scanf("%d", &den2);
    calcnum = (num1)*(num2);
    calcden = (den1)*(den2);
    printf("A multiplicação entre as fração é igual a: %d \n", calcnum);
    printf("                                           %d \n", calcden);
    return 0;
}
