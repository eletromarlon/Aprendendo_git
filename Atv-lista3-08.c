#include <stdio.h>

int main (){
    float valor;
    printf("Digite o valor em MB \n");
    scanf("%f", &valor);
    printf("\t O valor digitado em TB é %.2f \n", ((valor/1024)/1024));
    printf("\t O valor digitado em GB é %.2f \n", (valor/1024));
    printf("\t O valor digitado em MB é %.2f \n", valor);
    printf("\t O valor digitado em KB é %.2f \n", (valor*1024));
    printf("\t O valor digitado em Bytes é %.2f \n", ((valor*1024)*1024));
    return 0;
}
