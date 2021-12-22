#include <stdio.h>

int main () {
    float prod1;
    printf("Digite o preço do produto \n");
    scanf("%f", &prod1);
    //printf("Digite a 2ª nota \n");
    //scanf("%f", &nota2);
    printf("------------- Valor final do produto ---- \n");
    printf("Produto com 10%% de desconto ---- R$ %.2f \n", (prod1 - (prod1*0.1)));


    return 0;
}
