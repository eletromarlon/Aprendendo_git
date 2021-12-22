#include <stdio.h>

int main () {
    float horastrab, salmin;
    printf("Digite o total de horas trabalhadas \n Horas trabalhadas:   ");
    scanf("%f", &horastrab);
    printf("Digite o valor do salário mínimo atualmente \n R$    ");
    scanf("%f", &salmin);
    printf("------------Salário a receber ------------ \n");
    printf("O valor da hora trabalhada --------    %.2f \n", (salmin*0.05));
    printf("Salário Bruto ---------------------    %.2f \n", horastrab*(salmin*0.05));
    printf("Salário a receber neste mês -------    %.2f \n", (horastrab*(salmin*0.05)*0.97));


    return 0;
}
