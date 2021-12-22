#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int num, num0;
    printf("Digite um número inteiro positivo: \n");
    scanf(" %d", &num);
    num0 = num;
    while (num != 0 || num < 0)
    {

        printf("Digite outro número inteiro positivo! \n");
        scanf(" %d", &num);
        if (num<num0)
        {
            printf(" %d é maior \n", num0);
        }   else
            {
                printf(" %d é maior \n", num);
            }

    }



	return 0;
}
