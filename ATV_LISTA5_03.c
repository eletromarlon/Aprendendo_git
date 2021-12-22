#include <stdio.h>
#include <stdlib.h>

int main (){
    float peq, med, grand;
    printf("Digite a quantidade de camisas P \n");
    scanf("%f", &peq);
    printf("Digite a quantidade de camisas P \n");
    scanf("%f", &med);
    printf("Digite a quantidade de camisas P \n");
	scanf("%f", &grand);
	printf("+++++++++++++++Total de Vendas++++++++++++++++ \n");
	printf("Camisas +++++++++++++++++++++++++++++++  R$ %.2f  ", ((peq*10)+(med*12)+(grand*15)));
	return 0;
}
