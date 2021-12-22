#include <stdio.h>
#include <stdlib.h>

int main ()
{
    char tipo ;
    float vendas = 0, vendasV = 0, vendasP = 0;
    int num_vendas_prazo = 0, num_vendas_vista = 0;

        //printf("Digite o código I para iniciar ou S para sair: \n");
        //scanf(" %c", &tipo);

    while (tipo != 'S' && tipo != 's')
    {
        printf("Digite o código da venda: \n");
        scanf(" %c", &tipo);

        if (tipo=='V' || tipo=='v')
        {
            printf("Digite o valor da venda: \n");
            scanf(" %f", &vendas);
            vendasV = vendasV+vendas;
            num_vendas_vista++;
        }   else if (tipo=='P' || tipo=='p')
            {
                printf("Digite o valor da venda: \n");
                scanf(" %f", &vendas);
                vendasP = vendasP + vendas;
                num_vendas_prazo++;
            }

    }
    printf("O total de vendas foi ---------   %d \n", num_vendas_prazo+num_vendas_vista);
    printf("O médio das compras a prazo foi %.2f \n", vendasP/num_vendas_prazo);
    printf("O total de compras a vista ------ %d \n", num_vendas_vista);


	return 0;
}
