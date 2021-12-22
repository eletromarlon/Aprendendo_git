#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(){
    float km, haste, cabos, soma_cabos=0.0; //km, haste e cabos não precisam serem iniciadas
    int i=5;                                //pois receberão valores durante a execução

        do {
        printf("\n\tDigite o comprimento da ponte suspença (Entre 2 e 4)!\n\t");
        scanf("%f", &km);
            if (km<2)
                printf("\tValor abaixo do solicitado! \n");
            else if (km>4)
                printf("\tValor acima do solicitado! \n");
        } while ((km<2) || (km>4));

    km = km*1000;   //conversão para metros
    haste = km/20;  //atribuição do tamanho da haste

        for (i;i>0;i--){
            cabos = sqrt(((haste*i/5)*(haste*i/5)) + ((km*i/10)*(km*i/10)));
            soma_cabos += cabos;
        }

    soma_cabos = soma_cabos*4; //Multiplicação por 4 pois são 4 hastes

    printf("\n\tO total de cabos de aço em metros é: %.2f\n",soma_cabos);
}

