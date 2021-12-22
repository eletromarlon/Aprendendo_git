#include <stdio.h>

int main () {
    int num1;
    printf("Digite um número \n");
    scanf("%d", &num1);
    //printf("Digite a 2ª nota \n");
    //scanf("%f", &nota2);
    printf("--------------Resposta------------------ \n");
    printf("O quadrado de %d é %d                    \n", num1, (num1*num1));
    printf("O cubo de     %d é %d                    \n", num1, (num1*num1*num1));


    return 0;
}
