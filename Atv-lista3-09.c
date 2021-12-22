#include <stdio.h>

int main (){
    float km_i, km_f, val_comb, litros, tanque, calculo;
    printf("Digite a quilometragem inicial: \n");
    scanf("%f", &km_i);
    printf("Digite a quilometragem final: \n");
    scanf("%f", &km_f);
    printf("Digite o preço do combustível: \n");
    scanf("%f", &val_comb);
    printf("Digite o gasto em litros de combustível: \n");
    scanf("%f", &litros);
    printf("Digite o volume do tanque \n");
    scanf("%f", &tanque);
    printf("\t Foram rodados %.2f Km \n", km_f - km_i);
    calculo = (km_f - km_i)/litros;
    printf("\t O carro faz %.2f Km/l \n", calculo);
    calculo = ((km_f - km_i)/litros)*tanque;
    printf("\t O carro tem autonomia para %.2f Km \n", calculo);
    calculo = litros*val_comb;
    printf("\t Foram gastos R$ %.2f nesta viagem \n", calculo);


    return 0;
}
