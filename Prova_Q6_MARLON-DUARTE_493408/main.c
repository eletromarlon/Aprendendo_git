#include <stdio.h>
#include <stdlib.h>
#include "esfera.h"
#define pi 3.14

int main(){
    float x=60;
    int opc=1;

    while (opc != 0){

        printf("\n\n ----------------------- "); //Menu de opções para operação com a Fila;

        printf("\n 0 - Sair do programa");
        printf("\n 1 - Calcular o volume da esfera ");
        printf("\n 2 - Calcular a área da esfera ");
        printf("\n 3 - Descobrir o raio pelo volume ");
        printf("\n 4 - Descobrir o raio pela area ");

        printf("\n\n Escolha uma opcao: ");
        scanf("%d",&opc);

        switch (opc){

            case 0:{
                printf("\n\nPrograma encerrado!");
                continue;
            }
            case 1:{
                printf("\n\nCalculo do volume da esfera:");
                printf("\n\nDigite o valor do raio:");
                scanf("%f", &x);
                printf("\n\n O Volume da esfera é : %.2f", volume_esfera(x, pi));
            break;
            }
            case 2:{
                printf("\n\nCalculo da área da esfera:");
                printf("\nDigite o valor do raio:");
                scanf("%f", &x);
                printf("\nA área da esfera é : %.2f", area_esfera(x, pi));
            break;
            }
            case 3:{
                printf("\n\nEncontrar o raio da esfera pelo volume:");
                printf("\nDigite o volume de sua esfera: ");
                scanf("%f", &x);
                printf("\nO Volume da esfera é : %.2f", raio_esfera_volume(x, pi));
            break;
            }
            case 4:{
                printf("\n\nEncontrar o raio da esfera pela área:");
                printf("\nDigite a area de sua esfera: ");
                scanf("%f", &x);
                printf("\nO Volume da esfera é : %.2f", raio_esfera_area(x, pi));
            break;
            }
            default:{
                printf("\n\nAlgo deu errado!");
            }
        }
    }
    return 0;
}
