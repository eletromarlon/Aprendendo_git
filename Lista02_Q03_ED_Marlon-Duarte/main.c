#include <stdio.h>
#include <stdlib.h>
#include "numcomplex.h"

int main(){
    int opc;
    float x1, x2, y1, y2;
    do {
    printf("\n+++++++++ MENU +++++++++++");
    printf("\n1 Criar      -------------");
    printf("\n2 Apagar     -------------");
    printf("\n3 Soma       -------------");
    printf("\n4 Subtrai    -------------");
    printf("\n5 Multiplica -------------");
    printf("\n6 Sair       -------------\n");
    scanf("%d", &opc);
    } while ((opc < 1) && (opc > 6));

    if (opc == 6)
        return 0;

    switch (opc){

        case 1:
            printf("\nDigite os valores reais:\n");
            scanf("%f %f",&x1, &y1);
            cria(x1, y1);
            break;
        case 2:
            //nada ainda
            break;
        case 3:
            printf("\nDigite os valores reais:\n");
            scanf("%f %f",&x1, &y1);
            scanf("%f %f",&x2, &y2);
            soma(x1, y1, x2, y2);
            break;
        case 4:
            printf("\nDigite os valores reais:\n");
            scanf("%f %f",&x1, &y1);
            scanf("%f %f",&x2, &y2);
            subtrai(x1, y1, x2, y2);
            break;
        case 5:
            printf("\nDigite os valores reais:\n");
            scanf("%f %f",&x1, &y1);
            scanf("%f %f",&x2, &y2);
            multiplica(x1, y1, x2, y2);
            break;
        default: printf("Error!!!");

    }

}
