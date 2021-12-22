#include <stdio.h>

int main () {
    float sal1, vendas;
    printf("Digite o salário do funcionário \n");
    scanf("%f", &sal1);
    printf("Digite o total de vendas em reais \n");
    scanf("%f", &vendas);
    printf("--------Pagamento do Funcionário-------- \n");
    printf("O funcionário receberá neste mês:R$ %.2f \n", (sal1+(vendas*0.04)));


    return 0;
}
