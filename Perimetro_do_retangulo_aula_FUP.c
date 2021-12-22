#include <stdio.h>

int main( ){
    int num1, num2, num3;
    scanf ("%d %d %d", &num1, &num2, &num3);

    if ((num1 == num2) && (num2 == num3))
    {
    printf("Os tres numeros sao iguais");
    } else if ((num1 == num2) || (num2 == num3)|| (num1 == num3))
    {
    printf ("Dois números iguais e um diferente");
    }  else
    printf ("Não há números iguais");
    return 0;
}
