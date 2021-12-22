#include <stdio.h>

int main () {
    float sal1, aumento;
    printf("Digite o salário do funcionário \n");
    scanf("%f", &sal1);
    printf("Digite o percentual de aumento  \n");
    scanf("%f", &aumento);
    printf("--------------Aumento de salário-------- \n");
    printf("O novo salário do funcionário é R$  %.2f \n", (sal1*(1+aumento/100)) );


    return 0;
}
