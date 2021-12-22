#include <stdio.h>

int main (){
    int t, minutos, horas, total_de_minutos;
        printf("Digite o tempo de 4 dígitos:");
        scanf("%d", &t);
        horas = t/100; //Separando horas de minutos;
        minutos = t % 100; //guardando o valor de minutos;
        total_de_minutos = (horas*60)+minutos;
        printf("O tempo total em segundos é de %d", total_de_minutos*60);
    return 0;
}
