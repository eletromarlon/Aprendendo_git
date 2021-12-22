#include <stdio.h>
#include <stdlib.h>

int main (){
    int cod, idaVolta;
    float valor;
    printf("\t Destino # ida # ida e volta  \n");
    printf("\t   1   <= 500 =>   900       \n");
    printf("\t   2   <= 350 =>   650       \n");
    printf("\t   3   <= 300 =>   490       \n");
    printf("\t   4   <=  75 =>   140       \n");
    printf("\t   5   <=  30 =>    55       \n\n\n");

    printf("Digite o código da passagem: \n");

    scanf("%d", &cod);
    printf("Digita 1 => IDA ou 2 => IDA e VOLTA \n");
    scanf("%d", &idaVolta);
    switch (cod)
    {
    case 1:
        if (idaVolta == 1)
        {
        valor = 500;
        }else if (idaVolta == 2)
        {
        valor = 900;
        }else
        {
        printf("Erro na digitação dos códigos!");
        }
        break;
    case 2:
        if (idaVolta == 1)
        {
        valor = 350;
        }else if (idaVolta == 2)
        {
        valor = 650;
        }else
        {
        printf("Erro na digitação dos códigos!");
        }
        break;
    case 3:
        if (idaVolta == 1)
        {
        valor = 300;
        }else if (idaVolta == 2)
        {
        valor = 490;
        }else
        {
        printf("Erro na digitação dos códigos!");
        }
        break;
    case 4:
        if (idaVolta == 1)
        {
        valor = 75;
        }else if (idaVolta == 2)
        {
        valor = 140;
        }else
        {
        printf("Erro na digitação dos códigos!");
        }
        break;
    case 5:
        if (idaVolta == 1)
        {
        valor = 30;
        }else if (idaVolta == 2)
        {
        valor = 55;
        }else
        {
        printf("Erro na digitação dos códigos!");
        }
        break;
    default: printf("Erro na digitação dos códigos! \n");
    }
    printf("Total a pagar é: R$ %.2f", valor);
	return 0;
}
