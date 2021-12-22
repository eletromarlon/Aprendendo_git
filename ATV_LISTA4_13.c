#include <stdio.h>

int main () {
    float saco_racao, refeicao_gato;
    printf("Digite o peso do saco em Kg \n ");
    scanf("%f", &saco_racao);
    printf("Digite a quanto os gatos consomem em gramas \n");
    scanf("%f", &refeicao_gato);
    printf("------------Refeição do Gatos----------- \n");
    printf("Após 5 dias restarão no saco     %.2f Kg \n", ((saco_racao)-((refeicao_gato/1000)*2*5)) );


    return 0;
}
