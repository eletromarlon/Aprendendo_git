#include <stdio.h>

int main (){
    int hi, ho, val;
    printf("=====================================\n");
    printf("Digite a hora de chegada!============\n");
    printf("Somente números ex.:1230/1535/700=etc\n");
    scanf("%d", &hi);
    printf("Digite a hora de saída!==============\n");
    scanf("%d", &ho);
    printf("=====================================\n");
    val = (ho - hi);
    if ((hi<100) || (ho<100)){
        printf("Valor de entrada ou saida incorreto! \n" );
        }else{
            if ((hi>2400) || (ho>2400)){
                printf("Valor de entrada ou saida incorreto! \n" );
                }else{
                    if (val<=200){
                        printf("Valor total a pagar ==========R$ 1,00\n");
                        printf("Tempo de uso do estacionamento %dhs  \n", val);
                        }if ((val>200) && (val<500)){
                            printf("Valor total a pagar ==========R$ 1,40\n");
                            printf("Tempo de uso do estacionamento %dhs  \n", val);
                            }if (val>=500){
                                printf("Valor total a pagar ==========R$ 2,00\n");
                                printf("Tempo de uso do estacionamento %dhs  \n", val);
                                }
                        }
            }

}
