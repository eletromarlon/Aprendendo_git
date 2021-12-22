#include <stdio.h>

int main (){
    float pesoIdeal, altura;
    char genero;
    altura = 1.7;
    printf("Gênero:[M/F] ");
    scanf("%c", &genero);
    if (genero == 'M')
        pesoIdeal = (72.7 * altura) - 58;
    else
        pesoIdeal = (62.1 * altura) - 47.7;
    printf("Peso ideal: %f", pesoIdeal);

    return 0;

}
