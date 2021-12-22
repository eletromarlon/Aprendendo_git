#include <stdio.h>

int main (){
    char dig;
    int x;

    printf("Digite um caracter");
    scanf ("%c", &dig);
        if ((dig==65) || (dig==69) || (dig==73) || (dig==79) || (dig==85)){
            printf("%c é uma vogal em caixa alta", dig);
            }if ((dig>65) && (dig<91)){
                printf("Consoante em caixa alta");
                }if ((dig==97) || (dig==101) || (dig==105) || (dig==111) || (dig==117)){
                    printf("%c é uma vogal em caixa baixa", dig);
                    }if ((dig>97) && (dig<123)){
                        printf("Consoante em caixa baixa");
                        }if ((dig>47) && (dig<58)){
                            printf("%c é um número", dig);
                            }if ((dig<48) || ((dig>57) && (dig<65)) || ((dig>90) && (dig<97)) || (dig>123)){
                                printf("Valor digitado inválido!");
                            }

}
