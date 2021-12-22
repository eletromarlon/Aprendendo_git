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
    calcnum = (den2 * num1) + (den1 * num2);
    calcden = den1 * den2;
    printf("A adição entre as fração é igual a: %d \n", calcnum);
    printf("                                    %d \n", calcden);

    return 0;
}
