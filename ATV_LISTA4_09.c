#include <stdio.h>

int main () {
    float valorfabril, lucro, impostos;
    printf("Digite o valor de fábrica do veículo \n R$ ");
    scanf("%f", &valorfabril);
    printf("Digite o percentual de lucro pretendido \n");
    scanf("%f", &lucro);
    printf("Digite o percentual tributário do veículo \n");
    scanf("%f", &impostos);
    printf("------------Valor final do Carro -------- \n");
    printf("Lucros --------------------------- R$ %.2f \n", (valorfabril*lucro/100));
    printf("Impostos incidentes -------------- R$ %.2f \n", (valorfabril*impostos/100));
    printf("Valor do veículo ----------------- R$ %.2f \n", valorfabril+(valorfabril*lucro/100)+(valorfabril*impostos/100));
    return 0;
}
