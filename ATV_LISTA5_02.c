#include <stdio.h>
#include <stdlib.h>

int main (){
    float paes, broas;
    printf("Digite a quantidade de pães vendidos: \n");
    scanf("%f", &paes);
    printf("Digite a quantidade de broas vendidas: \n");
    scanf("%f", &broas);

    printf("==========Controle Padaria========== \n");
    printf("Vendas de pães---------------R$ %.2f \n", paes*0.15);
    printf("Vendas de broas--------------R$ %.2f \n", broas*1.5);
    printf("Total de vendas--------------R$ %.2f \n", (paes*0.15)+(broas*1.5));
    printf("Valor a guardar--------------R$ %.2f \n", (((paes*0.15)+(broas*1.5))*0.1));
    printf("Dinheiro em caixa------------R$ %.2f \n", ((paes*0.15)+(broas*1.5))-(((paes*0.15)+(broas*1.5))*0.1));


	return 0;
}
