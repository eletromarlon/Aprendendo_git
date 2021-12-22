#include <stdio.h>

int main () {
    float sal1, kw_h;
    printf("Digite o valor do salário mínimo \nR$   ");
    scanf("%f", &sal1);
    printf("Digite o consumo de energia \nR$   ");
    scanf("%f", &kw_h);
    printf("-------Cálculo do consumo de energia------ \n");
    printf("O valor do quilowatt      %.2f \n", sal1*0.0008);
    printf("O valor consumido no mês  %.2f \n", (sal1*0.0008)*kw_h);
    printf("O valor a pagar com desc. %.2f \n", ((sal1*0.0008)*kw_h)-((sal1*0.0008)*kw_h)*15/100);
    return 0;
}
