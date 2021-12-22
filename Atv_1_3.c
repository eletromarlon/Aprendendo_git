#include <stdio.h>

int main (){
    float produto;
    int desc;
    printf("=====================================\n");
    printf("Digite o valor do produto            \n");
    scanf("%f", &produto);
    printf("Qual a forma de pagamento?           \n");
    printf("<1> A VISTA EM DINHEIRO-----------10%\n");
    printf("<2> A VISTA EM CHEQUE-------------10%\n");
    printf("<3> A VISTA NO CARTAO-------------15%\n");
    printf("<4> PARCELADO 2X-------------------0%\n");
    printf("<5> PARCELADO 3X-----------------+10%\n");
    scanf("%d", &desc);
    printf("=====================================\n");

    switch (desc){
        case 1:
            printf("Total a pagar-----------------R$ %.2f\n", (produto - (produto*10/100)));
            break;

        case 2:
            printf("Total a pagar-----------------R$ %.2f\n", (produto - (produto*10/100)));
            break;

        case 3:
            printf("Total a pagar-----------------R$ %.2f\n", (produto - (produto*15/100)));
            break;

        case 4:
            printf("Total a pagar-----------------R$ %.2f\n", produto);
            break;

        case 5:
            printf("Total a pagar-----------------R$ %.2f\n", (produto + (produto*10/100)));
            break;

    }

    printf("=====================================\n");
}
