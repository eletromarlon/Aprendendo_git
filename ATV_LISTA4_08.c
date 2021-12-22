#include <stdio.h>

int main () {
    int nasc, ano;
    printf("Digite o ano de nascimento \n");
    scanf("%d", &nasc);
    printf("Digite o ano atual \n");
    scanf("%d", &ano);
    printf("--------------Cálculo da idade---------- \n");
    printf("A idade atual é de --------------   %d   \n", ano-nasc);
    printf("Em 2050 a idade será de ---------   %d   \n", 2050-nasc);


    return 0;
}
