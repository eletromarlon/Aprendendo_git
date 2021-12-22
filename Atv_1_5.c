#include <stdio.h>

int main(){
    float item;
    printf("=======================================\n");
    printf("Digite o valor do produto a cacular!===\n");
    scanf("%f", &item);
    printf("=======================================\n");
    if (item<20){
        printf("O produto passará ao custo de R$ %.2f \n", (item + (item * 45/100)));
        printf("=======================================\n");
    }else {
        printf("O produto passará ao custo de R$ %.2f \n", (item + (item * 30/100)));
        printf("=======================================\n");
    }
}
