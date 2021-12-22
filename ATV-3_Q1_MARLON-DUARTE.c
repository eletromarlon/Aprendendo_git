#include <stdio.h>
#include <stdlib.h>

float quant_passos (float dist, float passo){
    float result;

    passo = passo/100; //transformar em metros
    dist = dist*1000; //transforma em metros
    result = dist/passo;

    return result;
}

float quant_coloria(float temp, float vel, float peso){
    float result;

    result = temp * (vel * peso * 0.0175);

    return result;
}

int main (){
    int opcao = 0;
    float temp, vel, peso, passo, dist;

    do {
        printf("\t-----------------MENU DE OPCOES------------------- \n \n");
        printf("\t1 - Calcular calorias perdidas-------------------- \n");
        printf("\t2 - Calculadora de passos------------------------- \n");
        printf("\t3 - Sair------------------------------------------ \n\t");
        scanf("%d", &opcao);

            switch (opcao){

                case 1:
                    printf("\tDigite o tempo da corrida: (em minutos) \n\t");
                    scanf("%f",&temp);
                    printf("\tDigite a velocidade da corrida: (em Km/h) \n\t");
                    scanf("%f", &vel);
                    printf("\tDigite o seu peso: (em Kg) \n\t");
                    scanf("%f", &peso);

                    if ((temp>0) && (vel>0) && (peso>0)){
                        printf("\n\tA quantidade de calorias perdidas foram %.2f cal \n\n", quant_coloria(temp, vel, peso));
                    }   else {
                            printf("\t------Insira somente valores maiores que zero----- \n\n");
                        }
                break;
                case 2:
                    printf("\tDigite a distância percorrida: (em km) \n\t");
                    scanf("%f",&dist);
                    printf("\tDigite o tamanho de seu passo: (em centímetros) \n\t");
                    scanf("%f",&passo);

                    if ( (dist>0) && (passo>0) )
                    {
                        printf("\n\t %.1f passos dados em %.2f Km \n\n", quant_passos(dist, passo), dist);
                    } else {
                            printf("\t------Insira somente valores maiores que zero----- \n\n");
                            }
                break;
                case 3:
                    printf("\t--------------------Tchau!!!---------------------- \n");
                break;
                default:
                    printf("\tOpção inválida! \n\n");
                }
    }while (opcao != 3);
        printf("\t-------------------------------------------------- \n");
        printf("\t--------------Calculadora encerrada!-------------- \n");
        printf("\t-------------------------------------------------- \n");


}

