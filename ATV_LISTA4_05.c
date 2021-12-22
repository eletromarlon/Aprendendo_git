#include <stdio.h>

int main () {
    float salbase;
    printf("Digite o salário do funcionário \n");
    scanf("%f", &salbase);
    //printf("Digite a 2ª nota \n");
    //scanf("%f", &nota2);
    printf("------------Salário Final deste mês------ \n");
    printf("O salário final do unfionário é: R$ %.2f  \n", ((salbase*1.05)-(salbase*0.07)));


    return 0;
}
