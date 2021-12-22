#include <stdio.h>

int main () {
    float nota1, nota2;
    printf("Digite a 1ª nota \n");
    scanf("%f", &nota1);
    printf("Digite a 2ª nota \n");
    scanf("%f", &nota2);
    printf("--------------Média ponderada----------- \n");
    printf("Média ponderada das noras é:        %.2f \n", (2*nota1+3*nota2)/5);


    return 0;
}
