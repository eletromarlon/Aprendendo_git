#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int num1, num2;
    printf("Digite 2 números para contar: \n");
    scanf(" %d %d", &num1, &num2);
    while (num1<=num2)
    {
        printf("\t %d \n", num1);
        num1++;
    }


	return 0;
}
