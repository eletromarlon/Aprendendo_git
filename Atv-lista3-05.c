#include <stdio.h>

int main (){
    float km;
    int op;

    printf("Este programa pode converter Km <-> Cm /n");
    printf("Escolha: \n");
    printf("1 Para Km -> Cm \n");
    printf("2 Para Cm -> Km \n");
    scanf("%i", &op);
    switch (op)
    case 1:
    {
        printf("Digite o valor em Km \n");
        scanf("%f", &km);
        printf("Para converter, multiplica-se por 1000 transformando em metros e depois por 100\n");
        printf("%.2f Km em cm ficaria então: %.2f cm \n", km, ((km*1000)*100));
        break;
    case (2):
        printf("Digite o valor em Cm \n");
        scanf("%f", &km);
        printf("Para converter, divide-se por 100 transformando em metros e depois por 1000\n");
        printf("%.2f Cm em cm ficaria então: %.2f Km \n", km, ((km/100)/1000));
        break;

    default:

    printf("ERROR - CODIGO INVALIDO");
    }

    return 0;
}
